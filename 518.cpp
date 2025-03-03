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
#define endl '\n'
#define up upper_bound
#define low lower_bound
#define all(a) (a).begin(), (a).end()
#define bit(i, mask) (mask & (1 << i))
#define reset(a, val) memset(a, val, sizeof(val))
#define fu(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define int ll

constexpr int MOD = 998244353;
constexpr int mx = 1e2;
constexpr int maxn = 1 << 9;
constexpr int inf = 1e18 + 15;

int fact[mx + 5];
int invm[mx + 5];
int invf[mx + 5];
int len[mx + 5];
int dp[mx + 5][maxn][mx + 5];
int n, x;

void add(int &a, int b){a += b; if (a >= MOD) a -= MOD;};
void sub(int &a, int b){a -= b; if (a < 0) a += MOD;};

int daybit(int i, int mask){
    int a = max(1ll, i - x  + 1);
    int b = min(n, i + x - 1);

    int a_new = max(1LL, i - x + 2);
    int b_new = min(n, i + x);

    int giao = b_new - a + 1;
    int l = a_new - a;

    int new_mask = 0;
    fu(i, 0, giao - 1)
        if (bit(l + i, mask)) new_mask |= (1 << i);
    return new_mask;
}

void pre(){
    fact[1] = fact[0] = 1;
    invm[1] = invm[0] = 1;
    invf[1] = invf[0] = 1;
    fu(i, 2, mx){
        fact[i] = fact[i - 1]*i%MOD;
        invm[i] = MOD - MOD/i*invm[MOD%i]%MOD;
        invf[i] = invf[i - 1]*invm[i]%MOD;
    }
}

int C(int k, int n){
    if (k > n) return 0;
    return fact[n]*invf[k]%MOD*invf[n - k]%MOD;
}

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "file"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    pre();
    cin >> n >> x;

    fu(i, 1, n + 1){
        int a = max(1ll, i - x + 1);
        int b = min(n, i + x - 1);
        len[i] = b - a + 1;
    }

    dp[1][0][0] = 1;
    fu(i, 1, n){
        fu(mask, 0, (1 << len[i]) - 1){
            fu(j, 0, n){
                if (!dp[i][mask][j]) continue;

                int val = dp[i][mask][j];
                int new_mask = daybit(i, mask);
                add(dp[i + 1][new_mask][j], val);

                fu(k, 0, len[i] - 1){
                    if (bit(k, mask)) continue;
                    new_mask = daybit(i, mask | (1 << k));
                    add(dp[i + 1][new_mask][j + 1], val);
                }

            }
        }
    }
    
    int ans = 0;
    fu(i, 0, n){
        int val = 0;
        fu(mask, 0, (1 << len[n + 1]) - 1)
            add(val, dp[n + 1][mask][i]);
        val = val*fact[n - i]%MOD;
        if (i & 1) sub(ans, val);
        else add(ans, val);
    }
    cout << ans;
}