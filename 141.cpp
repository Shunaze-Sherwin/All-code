#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ld long double
#define ull unsigned ll
#define pa pair<int, int>
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
#define all(a) a.begin(), a.end()
#define fu(i,a,b) for (int i = (int)a; i <= (int)b; ++i)
#define fd(i,a,b) for (int i = (int)a; i >= (int)b; --i)
#define int ll

const int mod = 1e9 + 7;
const int mx = 2e5;

ll dp[mx + 5];
ll A[mx + 5], B[mx + 5];

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

    int n, s;
    cin >> n >> s;
    fu(i, 1, n) cin >> A[i] >> B[i];
    dp[0] = 1;
    fu(i, 1, n)
        fd(j, s, A[i])
            if (dp[j - A[i]] != 0) dp[j] = max(dp[j], dp[j - A[i]] + B[i]);
    ll ans = 0;
    fu(i, 1, s) ans = max(ans, dp[i] - 1);
    cout << ans;
}