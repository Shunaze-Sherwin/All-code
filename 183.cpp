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
#define bit(i, mask) ((mask) & (1ll << (i)))
#define reset(a, val) memset(a, val, sizeof(a))
#define fu(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)

constexpr int MOD = 1e9 + 7;
constexpr int mx = 5e3;
constexpr int maxn = 7;
constexpr int base = 1e4;
constexpr int LOG = log(mx);
constexpr ll inf = 1e18 + 15;

template<typename T> bool maximize(T &res, const T &val){if (val >= res){res = val; return true;} return false;}
template<typename T> bool minimize(T &res, const T &val){if (val <= res){res = val; return true;} return false;}

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

inline int Read_char(){
    char c = inchar();
    while (c != EOF && !isdigit(c)) c = inchar();
    return c;
}

int cost[mx + 5][mx + 5];
int X4[] = {1, 0, 0, -1};
int Y4[] = {0, 1, -1, 0};
int A[mx + 5][mx + 5];
int n;
queue<pa> qu[10];
 
void bfs(){
    qu[0].push({1, 1});
    cost[1][1] = 0;
    int remain = 1;
    while (remain){
        fu(i, 0, 9)
            while (qu[i].size()){
                int a = qu[i].front().fi;
                int b = qu[i].front().se;
                --remain;
                qu[i].pop();
                fu(j, 0, 3){
                    int u = a + X4[j];
                    int v = b + Y4[j];
                    int w = cost[a][b] + A[u][v];
                    if (u < 1 || v < 1 || u > n || v > n || w >= cost[u][v]) continue;
                    ++remain;
                    cost[u][v] = w;
                    qu[(i + A[u][v])%10].push({u, v});
                }
            }
    }
}
 
signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "COMNET"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    n = Read_int();
    fu(i, 1, n)
        fu(j, 1, n){
            char c = Read_char();
            A[i][j] = c - '0';
        }
    memset(cost, 1, sizeof(cost));
    bfs();
    cout << (cost[n][n] > n*n*9 ? -1 : cost[n][n]);
}
/*

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/