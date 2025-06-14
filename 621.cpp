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
constexpr int mx = 5e3;
constexpr int maxn = 1e2;
constexpr int LOG = log(mx);
constexpr ll inf = 1e14 + 15;

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

ll dp[mx + 5][mx + 5][2];
ll tmp[mx + 5][2];
vector<pa> g[mx + 5];
int n;

int dfs(int u, int p){
    dp[u][1][0] = dp[u][0][0] = 0;
    dp[u][1][1] = dp[u][0][1] = 0;
    int size_u = 1;
    for (auto &[v, w] : g[u]){
        if (v == p) continue;
        
        int limit = dfs(v, u);

        fu(i, 1, size_u + limit){
            tmp[i][0] = dp[u][i][0];
            tmp[i][1] = dp[u][i][1];
        }

        fu(i, 1, size_u)
            fu(j, 0, limit){
                dp[u][i + j][0] = min({dp[u][i + j][0], tmp[i][1] + dp[v][j][0] + w, dp[v][j][1] + tmp[i][0] + 2*w});
                dp[u][i + j][1] = min(dp[u][i + j][1], tmp[i][1] + dp[v][j][1] + 2*w);
            }
        size_u += limit;
    }
    return size_u;
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
    
    n = Read_int();
    fu(i, 1, n - 1){
        int u = Read_int();
        int v = Read_int();
        int w = Read_int();
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    fu(i, 1, n)
        fu(j, 0, n) dp[i][j][0] = inf, dp[i][j][1] = inf;
    dfs(1, 0);
    fu(i, 1, n) {
        cout << min(dp[1][i][0], dp[1][i][1]) << endl;
    }
}   
/* 

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/