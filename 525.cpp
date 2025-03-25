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
constexpr int mx = 5e5;
constexpr int maxn = 1e6;
constexpr int LOG = log(mx);
constexpr ll inf = 1e18 + 15;

void add(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
void sub(int &a, int b){a -= b; if (a < 0) a += MOD;}
void mul(int &a, int b){a = 1ll * (a%MOD) * (b%MOD) % MOD;}

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "maze"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll a = 0;
    int q;
    cin >> q;
    fu(i, 1, q){
        int c;
        cin >> c;
        if (c == 1){
            int x; 
            cin >> x;
            a ^= x;
        }
        if (c == 2) {
            if (a == 0) continue;
            int x = 63 - __builtin_clzll(a);
            a -= (1 << x);
        }
        if (c == 3) cout << __builtin_popcountll(a) << endl;
    }
}
/*

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/