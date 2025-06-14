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
constexpr int mx = 5e5;
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

#define Sieve
#ifdef Sieve    
    int ptr_pr = 0;
    int pr[mx + 5];
    int lpf[mx + 5];
    void Linear_sieve(int n = mx) {
        pr[++ptr_pr] = 2;

        lpf[1] = 1;
        fu(i, 2, n)
            lpf[i] = 2;

        for (int x = 3; x <= n; x += 2) {
            if (lpf[x] == 2) pr[++ptr_pr] = (lpf[x] = x);
            for (int i = 2; i <= ptr_pr && pr[i] <= lpf[x] && pr[i] * x <= n; ++i)
                lpf[pr[i] * x] = pr[i];
        }
    }
#endif

const int base = 31;

int divi[201];
int val[mx + 5];
ll invs[mx + 5];
ll pw[mx + 5];
int dem;
char A[mx + 5];
int n;

int pref[mx + 5][30];

int __pw(int a, int n) {
    int res = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) res = mul(res, a);
        a = mul(a, a);
    }
    return res;
}

void pre(){
    val[0] = 0;
    pw[0] = 1;
    fu(i, 1, n) pw[i] = 1ll * pw[i - 1] * base % MOD;
    fu(i, 1, n) {
        val[i] = 1ll * val[i - 1] * base % MOD;
        add(val[i], A[i] - 'a' + 1);
    }
    fu(i, 0, n)
        invs[i] = __pw(pw[i] - 1, MOD - 2);

    fu(i, 1, n) {
        fu(z, 0, 25)
            pref[i][z] = pref[i - 1][z];
        ++pref[i][A[i] - 'a'];
    }
}

int get(int l, int r){
    return (val[r] - 1ll * val[l - 1] * pw[r - l + 1] % MOD + MOD)%MOD;
}

void pt(int x){
    //cout << x << endl;

    int old = lpf[x], k = 0, ss = 0;
    divi[0] = 1;
    while (x > 1){
        ++k;
        x /= lpf[x];
        if (lpf[x] != old){
            int tmp = 1;
            int en = ss;
            fu(j, 1, k){
                tmp *= old;
                fu(i, 0, en){
                    ++ss;
                    divi[ss] = divi[i] * tmp;
                }
            }
            k = 0;
            old = lpf[x];
        }
    }

    dem = ss;

    //sort(divi, divi + ss + 1);
    //fu(i, 0, ss) cout << divi[i] << " \n"[i == ss];
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

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef Sieve
        Linear_sieve();
    #endif

    cin >> n;
    fu(i, 1, n) cin >> A[i];
    pre();
    
    int q;
    cin >> q;
    ostringstream ot;
    while (q--){
        int l, r;
        cin >> l >> r;
        int best = r - l + 1;
        int x = r - l + 1;
        while (x != 1){
            int tmp = best/lpf[x];
            if (get(l, r - tmp) == get(l + tmp, r)) best = tmp;
            x /= lpf[x];
        }

        ot << best << endl;
    }

    cout << ot.str();
}
/*

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/