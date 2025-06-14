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

char A[mx + 5];
char s[mx + 5];
int val[mx + 5];
int pw[mx + 5];
int n;
int base = 29;

void pre(){
    val[0] = 0, pw[0] = 1;
    fu(i, 1, n) pw[i] = 1ll * pw[i - 1] * base % MOD;
    fu(i, 1, n) {
        val[i] = 1ll * val[i - 1] * base % MOD;
        add(val[i], A[i] - 'a' + 1);
    }
}

int get(int l, int r){
    return (val[r] - 1ll * val[l - 1] * pw[r - l + 1] % MOD + MOD) % MOD;
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

    cin >> s;
    n = strlen(s);
    int mold = 0;
    fu(i, 0, n - 1) {
        mold = 1ll * mold * base % MOD;
        add(mold, s[i] - 'a' + 1);
    }
    cin >> A;  
    n = strlen(A);  
    memmove(A + 1, A, n);
    pre();
    ll ans = 0;
    fu(i, 1, n)
        fu(j, i + 1, n - 1){
            array<pa, 3> tmp;
            tmp[0] = {get(1, i), i};
            tmp[1] = {get(i + 1, j), j - i};
            tmp[2] = {get(j + 1, n), n - j};
            sort(all(tmp));
            do{
                int x = tmp[0].fi;
                fu(i, 1, 2){
                    x = 1ll * x * pw[tmp[i].se] % MOD;
                    add(x, tmp[i].fi);
                }
                if (x == mold){
                    ++ans;
                    break;
                }
            } while (next_permutation(all(tmp)));
        }
    cout << ans;
}   
/* 

  /\__/\
 (=^.^= )
 (") (")_/ 

~~~-Sherwin-~~~

*/