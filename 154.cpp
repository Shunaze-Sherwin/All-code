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
#define up upper_bound
#define low lower_bound
#define all(a) (a).begin(), (a).end()
#define bit(i, mask) (mask & (1 << i))
#define reset(a, val) memset(a, val, sizeof(a))
#define fu(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define int ll

constexpr int MOD = 123456789;
constexpr int mx = 1e6;
constexpr int inf = 1e18 + 15;

void add(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
void sub(int &a, int b){a -= b; if (a < 0) a += MOD;}
void mul(int &a, int b){a = 1ll * (a%MOD) * (b%MOD) %MOD;}

int f[mx + 5];
int dp[mx + 5];

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

    int n;
    cin >> n;
    int ans = 0;
    fill(f, f + mx + 1, -1);
    dp[0] = 0;
    fu(i, 1, n){
        int x;
        cin >> x;
        dp[i] = (dp[i - 1]*2 - f[x] + MOD)%MOD;
        f[x] = dp[i - 1];
    }
    cout << dp[n];
}
/*

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/