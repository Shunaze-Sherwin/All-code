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
constexpr int maxn = 5e5;
constexpr int LOG = log(mx);
constexpr ll inf = 1e18 + 15;

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

int D[31];
int A[mx + 5];

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

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n = Read_int();
    fu(i, 1, n) A[i] = Read_int();
    sort(A + 1, A + n + 1);
    int j = 1;
    ll ans = 0;
    int cnt = 0;
    fu(i, 1, n){
        while (j <= n && (__lg(A[i]) > __lg(A[j]) || A[j] == 0)){
            int val = 0;
            fd(k, 30, 0){
                if (bit(k, A[j])) {
                    ++D[k]; break;
                }
            }
            ++j;
        }

        int x = A[i];
        if (x == 0) {
            ans += ++cnt;
            continue;
        }

        int p = __lg(x);
        int limit = max(0, p - 1);
        fd(k, limit, 0)
           if (bit(k, x)) ans += D[k];
        ans += cnt;
    }
    cout << ans;
}   
/* 

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/