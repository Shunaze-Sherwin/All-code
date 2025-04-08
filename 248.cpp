#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define pa pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define log __lg
#define endl '\n'
#define upper upper_bound
#define lower lower_bound
#define all(a) (a).begin(), (a).end()
#define bit(i, mask) (mask & (1ll << (i)))
#define reset(a, val) memset(a, val, sizeof(a))
#define fu(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)

constexpr int MOD = 1e5 + 3;
constexpr int mx = 1e5;
constexpr int maxn = 1e4;
constexpr int LOG = log(mx);
constexpr ll inf = 1e18 + 15;

void add(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
void sub(int &a, int b){a -= b; if (a < 0) a += MOD;}

int mul(int a, int b){
    return 1ll * (a%MOD) * (b%MOD) % MOD;
}

int num[mx + 5] = { };
int low[mx + 5] = { };
vector<pa> g[mx + 5];
bool point[mx + 5] = { };
bool bridge[mx + 5] = { };
bool vi[mx + 5] = { };
int seen[mx + 5] = { };
int nowtime = 0;
int ma, vt;

void dfs(int u, int pre){
    num[u] = low[u] = ++nowtime;
    int child = 0;
    for (auto &[v, id] : g[u]){
        if (vi[id]) continue;
        vi[id] = true;
        if (!num[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            ++child;
            if (num[v] == low[v]) bridge[id] = true;
            if (pre == u){
                if (child > 1) point[u] = true;
            }
            else if (low[v] >= num[u]) point[u] = true;
        }
        else low[u] = min(low[u], num[v]);
    }
}

void length(int u, int k, int p){
    seen[u] = p;
    if (ma < k) ma = k, vt = u;
    for (auto &[v, id] : g[u])
        if (seen[v] < p)
            length(v, k + bridge[id], p);
}

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "XDBS"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
    cin >> n >> m;
    fu(i, 1, m){
		int a, b;
        cin >> a >> b;
        g[a].pb({b, i});
        g[b].pb({a, i});
    }
    fu(i, 1, n)
        if (!num[i]) dfs(i, i);
    ma = 0;
    fu(i, 1, n)
        if (!seen[i]){
            vt = i;
            length(i, 0, 1);
            length(vt, 0, 2);
        }
    cout << ma;
}
/*

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/