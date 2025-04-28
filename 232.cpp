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
constexpr int mx = 1e5;
constexpr int maxn = 1 << 20;
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

int dp[mx + 5][3] = { };
vector<int> g[mx + 5];
bool vi[mx + 5];

int dfs(int u, int p, int col) {
    int &res = dp[u][col];
    if (res != -1)
        return res;

    res = 1;
    for (int v: g[u]) {
        if (v == p) continue;
        int mul = 0;
        for (int c = 0; c <= 2; ++c) if (c != col)
            mul += dfs(v, u, c);
        res *= mul;
    }
    return res;
}

int lt(int a, int b){
    if (b == 0) return 1;
    int x = lt(a, b/2);
    if (b & 1) return x*x%MOD*a%MOD;
    return x*x%MOD;
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
    
    int n = Read_int();
    fu(i, 1, n - 1){
        int u = Read_int();
        int v = Read_int();
        g[u].pb(v);
        g[v].pb(u);
    }
    reset(dp, -1);
    //cout << dfs(1, 0, 0) + dfs(1, 0, 1) + dfs(1, 0, 2);
    cout << 3*lt(2, n - 1)%MOD;
}   
/* 

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/