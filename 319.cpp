#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned ll
#define pa pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define gcd __gcd
#define log __lg
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define all(a) a.begin(), a.end()
#define fu(i,a,b) for (int i = (int)a; i <= (int)b; ++i)
#define fd(i,a,b) for (int i = (int)a; i >= (int)b; --i)

const int mod = 1e9 + 7;
const int mx = 1e5;

int par[mx + 5], sz[mx + 5], ans[mx + 5];

int find(int u){
    if (u == par[u]) return u;
    return par[u] = find(par[u]);
}

void join(int u, int v){
    int a = find(u), b = find(v);
    if (sz[a] < sz[b]) swap(a, b);
    if (a != b){
        par[b] = a;
        sz[a] += sz[b];
    }
}

struct gt{
    int u, v, w;
};

gt v[mx + 5]; 

bool com(gt a, gt b){
    return a.w > b.w;
}

struct pl{
    int id, c, w;
};

bool cmp(pl a, pl b){
    return a.w < b.w;
}

pl Q[mx + 5];

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "file"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
        freopen(name".ERR", "w", stderr);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    v[n] = {0, 0, 0};
    fu(i, 1, n - 1) cin >> v[i].u >> v[i].v >> v[i].w;
    sort(v + 1, v + n, com);
    Q[0] = {0, 0, -1};
    fu(i, 1, q){
        Q[i].id = i;
        cin >> Q[i].c >> Q[i].w;
    }
    sort(Q + 1, Q + q + 1, cmp);
    fu(i, 1, n) par[i] = i, sz[i] = 1;
    int j = q;
    fu(i, 1, n - 1){
        join(v[i].u, v[i].v);
        if (v[i + 1].w != v[i].w){
            while (Q[j].w > v[i].w){
                ans[Q[j].id] = 0;
                --j;
            }
            while (Q[j].w == v[i].w){
                ans[Q[j].id] += sz[find(Q[j].c)] - 1;
                --j;
            }
            while (Q[j].w > v[i + 1].w){
                ans[Q[j].id] = 0;
                --j;
            }
            int old = j;
            while (Q[j].w == v[i + 1].w){
                ans[Q[j].id] -= sz[find(Q[j].c)] - 1;
                --j;
            }
            
            j = old;
        }
    }
    fu(i, 1, q) cout << max(ans[i], 0) << endl;
}