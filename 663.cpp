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
#define int ll

constexpr int MOD = 1e9 + 7;
constexpr int mx = 3e5;
constexpr int maxn = 1e4;
constexpr int LOG = log(mx);
constexpr ll inf = 1e18 + 15;

void add(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
void sub(int &a, int b){a -= b; if (a < 0) a += MOD;}

int mul(int a, int b){
    return 1ll * (a%MOD) * (b%MOD) % MOD;
}

static const int SIZE = 1 << 16;
char Achar[SIZE];
int cpos = SIZE, clen = SIZE;

inline int inchar(){
    if (cpos == clen){
        clen = (int)fread(Achar, 1, SIZE, stdin);
        if (clen == 0) return EOF;
        cpos = 0;
    }
    return Achar[cpos++];
}

inline int Read_int(){
    int x = 0;
    char c = inchar();
    int p = 1;
    while (c != EOF && (c < '0' || c > '9') && c != '-') c = inchar();
    if (c == '-') p = -1, c = inchar();
    while (c != EOF && (c >= '0' && c <= '9')) x = x*10 + (c - '0'), c = inchar();
    return x * p;
}

int num[mx + 5] = { };
int low[mx + 5] = { };
vector<pa> g[mx + 5] = { };
vector<int> tree[mx + 5];
int bridge[mx + 5];
pa edge[mx + 5];
bool vi[mx + 5] = { };
int cnt;
int nowtime = 0;

void dfs(int u, int pre){
    num[u] = low[u] = ++nowtime;
    for (auto &[v, id] : g[u]){
        if (v == pre) continue;
        if (!num[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) bridge[id] = true;
        }
        else low[u] = min(low[u], num[v]);
    }
}

void calc(int u){
    vi[u] = true;
    for (int v : tree[u])
        if (!vi[v]){
            ++cnt;
            calc(v);
        }
}

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "temp-loops"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n = Read_int(), m = Read_int();
    fu(i, 1, m){
        edge[i].fi = Read_int(), edge[i].se = Read_int();
        g[edge[i].se].pb({edge[i].fi, i});
        g[edge[i].fi].pb({edge[i].se, i});
    }

    fu(i, 1, n)
        if (!num[i]) dfs(i, i);

    fu(i, 1, m)
        if (bridge[i]){
            tree[edge[i].se].pb(edge[i].fi);
            tree[edge[i].fi].pb(edge[i].se);
        }

    int ans = 0;
    fu(i, 1, n)
        if (!vi[i]) {
            cnt = 1;
            calc(i);
            ans += (cnt - 1)*cnt/2;
        }
    cout << ans;
}
/*

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/