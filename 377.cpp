#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned ll
#define pa pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define gcd __gcd
#define log __lg
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define all(a) (a).begin(), (a).end()
#define fu(i,a,b) for (int i = (int)a; i <= (int)b; ++i)
#define fd(i,a,b) for (int i = (int)a; i >= (int)b; --i)

const int mod = 100;
const int mx = 5e2;
const ll inf = 1e18;

pa dp[mx + 5][mx + 5];
ll A[mx + 5];

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

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    fu(i, 1, n) cin >> A[i];
    fu(i, 1, n) fill(dp[i] + 1, dp[i] + n + 1, mp(inf, 0));
    fu(i, 1, n) dp[i][i] = {0, A[i]};
    fd(i, n, 1)
        fu(j, i + 1, n){
            fu(k, i, j - 1){
                ll val = dp[i][k].se * dp[k + 1][j].se;
                if (dp[i][j].fi > dp[i][k].fi + dp[k + 1][j].fi + val){
                    dp[i][j].fi = dp[i][k].fi + dp[k + 1][j].fi + val;
                    dp[i][j].se = (dp[i][k].se + dp[k + 1][j].se)%mod;
                }
            }
        }
    cout << dp[1][n].fi;
}