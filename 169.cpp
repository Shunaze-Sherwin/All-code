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
constexpr int maxn = 7;
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

char A[mx + 5][mx + 5];
int val[mx + 5][mx + 5];
int pw[mx + 5];
int base = 31;
int n, m, q;

void pre(){
    fu(i, 1, n) val[i][0] = 0;
    pw[0] = 1;
    fu(i, 1, m) pw[i] = 1ll * pw[i - 1] * base % MOD;
    fu(i, 1, n) fu(j, 1, m) {
        val[i][j] = 1ll * val[i][j - 1] * base % MOD;
        add(val[i][j], A[i][j] - '0' + 1);
    }
}

int get(int l, int r, int lv){
    return (val[lv][r] - 1ll * val[lv][l - 1] * pw[r - l + 1] % MOD + MOD)%MOD;
}

bool check(int a, int b, int c, int d){
    int mold[2];
    mold[0] = mold[1] = 0;
    fu(i, b, d){
        mold[0] = 1ll * mold[0] * base % MOD;
        mold[1] = 1ll * mold[1] * base % MOD;
        add(mold[0], A[a][i] - '0' + 1);
        add(mold[1], ((A[a][i] - '0') ^ 1) + 1);
    }

    fu(i, a + 1, c){
        int x = get(b, d, i);
        if (x != mold[0] && x != mold[1]) return false;
    }
    return true;
}

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "JEWELRY"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> q;
    fu(i, 1, n)
        fu(j, 1, m) cin >> A[i][j];
    pre();
    while (q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (!check(a, b, c, d)) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}   
/* 

  /\__/\
 (=^.^= )
 (") (")_/ 

~~~-Sherwin-~~~

*/