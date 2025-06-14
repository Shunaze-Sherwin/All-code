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

constexpr int MOD = 1e9 + 7;
constexpr int mx = 1e5;
constexpr int maxn = 7;
constexpr int LOG = log(mx);
constexpr ll inf = 1e9 + 15;

int Rand(int l, int r){
    return l + 1ll * rd() %(r - l + 1);
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

constexpr int nummod = 1;

int rmd[3] = {(int)1e9 + 7, (int)1e9 + 3, 119*(1 << 23) + 1};
int val[mx + 5][nummod];
char A[mx + 5];
int n;
int pw[mx + 5][nummod];
map<int, int> cnt;

void pre(){
    int base = 29;
    fu(i, 0, nummod - 1) val[0][i] = 0, pw[0][i] = 1;
    fu(i, 0, nummod - 1) fu(j, 1, n) pw[j][i] = 1ll * pw[j - 1][i] * base % rmd[i];
    fu(i, 0, nummod - 1) fu(j, 1, n) val[j][i] = (1ll * val[j - 1][i] * base + A[j] - 'a' + 1) % rmd[i];
}

int get(int l, int r){
    return (val[r][0] - 1ll * val[l - 1][0] * pw[r - l + 1][0] % rmd[0] + rmd[0])%rmd[0];
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

    cin >> A;
    n = strlen(A);
    memmove(A + 1, A, n);
    A[0] = '%';
    A[n + 1] = '#';
    pre();
    int k;
    cin >> k;
    int l = 1, r = n;
    while (r >= l){
        int mid = (l + r) >> 1;
        int ma = 0;
        bool check = false;
        cnt.clear();
        fu(i, 1, n - mid + 1){
            int tmp = get(i, i + mid - 1);
            ma = max(ma, ++cnt[tmp]);
            if (ma >= k) {
                check = true;
                break;
            }
        }
        if (check) l = mid + 1;
        else r = mid - 1;
    }
    cout << r;
}   
/* 

  /\__/\
 (=^.^= )
 (") (")_/ 

~~~-Sherwin-~~~

*/