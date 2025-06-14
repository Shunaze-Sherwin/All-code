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

constexpr int MOD = 1e9 + 7;
constexpr int mx = 5e2;
constexpr int maxn = 1e2;
constexpr int LOG = log(mx);
constexpr ll inf = 1e9 + 15;

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

vector<int> g[mx + 5];
int dp[mx + 5][mx + 5];
int sm[mx + 5];
int n, l;

void dfs(int u, int p){
    for(int v : g[u]){
        if (v == p) continue;
        dfs(v, u);
        fd(i, sm[u], 0)
            fu(j, 0, min(i, sm[v]))
                dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[v][j]);
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

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    n = Read_int(), l = Read_int();
    fu(u, 2, n){
        int v = Read_int();
        g[v].pb(u);
    }
    fu(i, 1, n) sm[i] = Read_int();
    fu(i, 1, n)
        fu(j, 0, l) dp[i][j] = Read_int();
    dfs(1, 0);
    int ans = 0;
    fu(i, 0, sm[1]) ans = max(ans, dp[1][i]);
    cout << ans;
}   
/* 

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/