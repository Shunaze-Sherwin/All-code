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
#define int ll

constexpr int MOD = 1e9 + 7;
constexpr int mx = 2e5;
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

ll cost[mx + 5];
vector<pa> g[mx + 5];
int rev[mx + 5];

void dijkstra(){
    priority_queue<pa, vector<pa>, greater<pa>> qu;
    qu.push({0, 1});
    while (qu.size()){
        int u = qu.top().se;
        int cs = qu.top().fi;
        qu.pop();
        if (cs > cost[u]) continue;
        for (auto &[v, w] : g[u]){
            if (cs + w >= cost[v]) continue;
            cost[v] = cs + w;
            rev[v] = u;
            qu.push({cost[v], v});
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

    int n = Read_int(), m = Read_int();
    fu(i, 1, m){
        int u = Read_int();
        int v = Read_int();
        int w = Read_int();
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    reset(cost, 1);
    dijkstra();
    if (cost[n] > n*1e9){
        cout << -1;
        return 0;
    }
    cout << cost[n] << endl;
    int val = n;
    vector<int> v;
    v.pb(n);
    while (val != 1){
        val = rev[val];
        v.pb(val);
    }
    reverse(all(v));
    for (int x : v) cout << x << char(32);
}
/*

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/