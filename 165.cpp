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

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

constexpr int MOD = 1e9 + 9;
constexpr int mod = 119*(1 << 23) + 1;
constexpr int mx = 1e6;
constexpr int maxn = 1e2;
constexpr int LOG = log(mx);
constexpr ll inf = 1e9 + 15;

int Rand(int l, int r){
    return l + rd()%(r - l + 1);
}

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

string s, t;
int loop[mx + 5];

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

    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s = '%' + s + '%';
    t = '#' + t + '#';
    loop[1] = 0;
    int j = 0;
    fu(i, 2, m)
        loop[i] = (t[i] == t[j + 1] ? ++j : (j = 0));
    j = 0;
    int ans = 0;
    fu(i, 1, n){
        while (j && s[i] != t[j + 1]) j = loop[j];
        if (s[i] == t[j + 1]) ++j;
        if (j == m) ++ans;
    }
    cout << ans;
}   
/* 

  /\__/\
 (=^.^= )
 (") (")_/ 

~~~-Sherwin-~~~

*/