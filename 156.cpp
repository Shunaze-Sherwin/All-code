#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ull unsigned ll
#define pa pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define gcd __gcd
#define log __lg
#define lower lower_bound
#define upper upper_bound
#define all(a) a.begin(), a.end();
#define search binary_search
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)
#define int ll

const int mx = 1e2;
const int mod = 1e9 + 7;

ll A[mx + 5], B[mx + 5], C[mx + 5];
ll dp[mx + 5][mx*mx + 5] = { };

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "SEED"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, s;
    cin >> n >> s;
    fu(i, 1, n) cin >> A[i] >> B[i] >> C[i];
    fu(i, 1, n)
        fd(j, s, A[i]){
                fu(k, 0, min(C[i], j/A[i]))
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - A[i]*k] + k*B[i]);
            }
    ll ans = 0;
    fu(i, 1, s) ans = max(ans, dp[n][i]);
    cout << ans;
}