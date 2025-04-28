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

constexpr int MOD = 1e9 + 7;
constexpr int mx = 1e6;
constexpr int maxn = 1e2;
constexpr int LOG = log(mx);
constexpr ll inf = 1e14 + 15;

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

multiset<int> s1;
multiset<int> s2;

void add(int x){
    auto r = s1.lower(x);
    if (r != s1.begin()){
        auto l = prev(r);
        if (r != s1.end()) s2.erase(s2.find((*l) ^ (*r)));
        s2.insert((*l) ^ x);
    }
    if (r != s1.end()) s2.insert(x ^ (*r));
    s1.insert(x);
}

void remove(int x){
    if (s1.empty()) return ;
    auto mid = s1.find(x);
    auto r = next(mid);
    if (mid != s1.begin()){
        auto l = prev(mid);
        s2.erase(s2.find((*l) ^ x));
        if (r != s1.end()) s2.insert((*l) ^ (*r));
    }
    if (r != s1.end()) s2.erase(s2.find(x ^ (*r)));
    s1.erase(mid);
}

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

    int q = Read_int();
    ostringstream ot;
    while (q--){
        int c = Read_int();
        if (c == 1){
            int x = Read_int();
            add(x);
        }
        if (c == 2){
            int x = Read_int();
            remove(x);
        }
        if (c == 3){
            ot << *s2.begin() << endl;
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