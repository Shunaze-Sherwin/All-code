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
constexpr int mx = 2e3;
constexpr int maxn = 7;
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
    while (c != EOF && (c != '.' && c != '#')) c = inchar();
    return c;
}

int cost[mx + 5][mx + 5][4];
int A[mx + 5][mx + 5];
int X4[] = {1, 0, 0, -1};
int Y4[] = {0, 1, -1, 0};
int n;

struct gt{
    int x, y, type;
};

void bfs(){
    deque<gt> qu;
    qu.push_front({1, 1, 0});
    cost[1][1][0] = 0;
    while (qu.size()){
        gt tmp = qu.front();
        qu.pop_front();
        fu(i, 0, 3){
            if (i == 3 - tmp.type) continue;

            int a = tmp.x + X4[i];
            int b = tmp.y + Y4[i];

            if (a < 1 || b < 1 || a > n || b > n || A[a][b] == '#') continue;

            if (i == tmp.type){
                if (cost[a][b][i] <= cost[tmp.x][tmp.y][i]) continue;

                cost[a][b][i] = cost[tmp.x][tmp.y][i];
                qu.push_front({a, b, i});
                continue;
            }
            
            if (cost[a][b][i] <= cost[tmp.x][tmp.y][tmp.type] + 1) continue;
            cost[a][b][i] = cost[tmp.x][tmp.y][tmp.type] + 1;
            qu.push_back({a, b, i});
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
        fu(j, 1, n) A[i][j] = Read_char();
    reset(cost, 1);
    bfs();
    int ans = cost[0][0][0];
    fu(i, 0, 3) minimize(ans, cost[n][n][i]);
    cout << (ans > n*n ? -1 : ans);
}
/*

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/