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
#define int ll

constexpr int MOD = 1e5 + 3;
constexpr int mx = 1e5;
constexpr int maxn = 30;
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

int A[mx + 5];
int B[mx + 5];
int IT[maxn + 5][4*mx];
int lazy[maxn + 5][4*mx];

void build(int id, int l, int r, int x){
    if (l == r){
        IT[x][id] = (bit(x - 1, B[l]) > 0);
        return ;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid, x);
    build(id << 1 | 1, mid + 1, r, x);
    IT[x][id] = IT[x][id << 1] + IT[x][id << 1 | 1];
}

void down(int id, int l, int r, int x){
    if (l == r || !lazy[x][id]) return ;
    int mid = (l + r) >> 1;

    IT[x][id << 1] *= -1;
    IT[x][id << 1] += mid - l + 1;

    IT[x][id << 1 | 1] *= -1;
    IT[x][id << 1 | 1] += r - mid;

    lazy[x][id] = 0;
    lazy[x][id << 1] ^= 1;
    lazy[x][id << 1 | 1] ^= 1;
}

void update(int id, int l, int r, int u, int v, int x){
    if (v < l || r < u) return ;
    if (u <= l && r <= v){
        IT[x][id] *= -1;
        IT[x][id] += r - l + 1;

        lazy[x][id] ^= 1;
        return ;
    }
    int mid = (l + r) >> 1;
    down(id, l, r, x);
    update(id << 1, l, mid, u, v, x);
    update(id << 1 | 1, mid + 1, r, u, v, x);
    IT[x][id] = IT[x][id << 1] + IT[x][id << 1 | 1];
}

int get(int id, int l, int r, int u, int v, int x){
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return IT[x][id];
    int mid = (l + r) >> 1;
    down(id, l, r, x);
    return get(id << 1, l, mid, u, v, x) + get(id << 1 | 1, mid + 1, r, u, v, x);
}

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "DI"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n = Read_int(), q = Read_int();
    B[1] = 0;
    A[1] = 0;
    ++n;
    fu(i, 2, n) {
        A[i] = Read_int();
        B[i] = B[i - 1]^A[i];
    }

    fu(i, 1, 30) build(1, 1, n, i);
    ostringstream ot;

    while (q--){
        int c = Read_int();
        if (c == 1){
            int id = Read_int(), val = Read_int();
            ++id;

            fu(i, 0, 29){
                int a = bit(i, A[id]);
                int b = bit(i, val);
                if (a == b) continue;
                update(1, 1, n, id, n, i + 1);
                A[id] ^= (1 << i);
            }
        }

        if (c == 2){
            int l = Read_int(), r = Read_int();
            ++r;
            int ans = 0;

            fu(i, 0, 29){
                int cnt = get(1, 1, n, l, r, i + 1);
                ans += cnt*(r - l + 1 - cnt)*(1 << i);
            }
            ot << ans << endl;
        }
    }
    cout << ot.str();
}
/*

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/