#include <bits/stdc++.h>

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
#define all(a) (a).begin(), (a).end()
#define fu(i,a,b) for (int i = (int)a; i <= (int)b; ++i)
#define fd(i,a,b) for (int i = (int)a; i >= (int)b; --i)

const int mod = 31011;
const int mx = 1e2;

int par[mx + 5], rnk[mx + 5];
int remain;

struct dsu_save{
    int u, rnku, v, rnkv;
};

stack<dsu_save> op;

void roll_back(){
    if (op.empty()) return ;
    dsu_save x = op.top();
    op.pop();
    ++remain;
    par[x.u] = x.u;
    rnk[x.u] = x.rnku;
    par[x.v] = x.v;
    rnk[x.v] = x.rnkv;
}

int find(int u){
    if (u == par[u]) return u;
    return find(par[u]);
}

bool join(int u, int v){
    u = find(u), v = find(v);
    if (u == v) return false;
    if (rnk[u] > rnk[v]) swap(u, v);
    --remain;
    op.push({u, rnk[u], v, rnk[v]});
    par[u] = v;
    if (rnk[u] == rnk[v]) ++rnk[v];
    return true;
}

struct gt{
    int u, v, w;
};

vector<gt> v;

bool com(gt a, gt b){
    return a.w < b.w;
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
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    fu(i, 1, m){
        int a, b, w;
        cin >> a >> b >> w;
        v.pb({a, b, w});
    }
    remain = n;
    fu(i, 1, n) par[i] = i, rnk[i] = 0;
    sort(all(v), com);
    int ans = 1;
    for (int l = 0; l < v.size(); ++l){
        int r = l;
        while (r < v.size() && v[r].w == v[l].w) ++r; --r;

        int cnt = 0;
        fu(i, l, r) cnt += join(v[i].u, v[i].v);
        fu(i, 1, cnt) roll_back();

        int last = (1 << (r - l + 1)) - 1;

        int res = 0;
        fu(mask, 0, last){
            int bit = __builtin_popcount(mask), k = 0;
            if (bit != cnt) continue;

            fu(i, l, r)
                if (mask & (1 << (i - l))){
                    k += join(v[i].u, v[i].v);
                }

            if (k == cnt) ++res;
            fu(i, 1, k) roll_back();
        }

        fu(i, l, r) join(v[i].u, v[i].v);
        ans *= res;
        ans %= mod;
        l = r;
    }
    cout << (remain == 1 ? ans : 0);
}