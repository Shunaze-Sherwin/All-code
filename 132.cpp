#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
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
#define int ll

const int mod = 1e9 + 7;
const int mx = 1e6;
const int sm = 1e6;

int par[mx + 5];
int sz[mx + 5];
int A[mx + 5];

int find(int u){
    if (par[u] == u) return u;
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
    int u, v;
};

vector<gt> res;

bool com(gt a, gt b){
    return max(A[a.u], A[a.v]) < max(A[b.u], A[b.v]);
}

bool cmp(gt a, gt b){
    return min(A[a.u], A[a.v]) > min(A[b.u], A[b.v]);
}

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
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    fu(i, 1, n) cin >> A[i];
    fu(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        res.pb({u, v});
    }
    sort(all(res), com);
    fu(i, 1, n) par[i] = i, sz[i] = 1;
    ll ma = 0;
    for (gt i : res){
        ma += sz[find(i.u)]*sz[find(i.v)]*max(A[i.u], A[i.v]);
        join(i.u, i.v);
    }
    fu(i, 1, n) par[i] = i, sz[i] = 1;
    sort(all(res), cmp);
    ll mi = 0;
    for (gt i : res){
        mi += sz[find(i.u)]*sz[find(i.v)]*min(A[i.u], A[i.v]);
        join(i.u, i.v);
    }
    cout << ma - mi;
}