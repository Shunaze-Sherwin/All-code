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
const int mx = 1e5;

ll dp[mx + 5][2][3] = { };
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

    int n;
    cin >> n;
    fu(i, 1, n) cin >> A[i];
    fu(i, 1, n) cin >> B[i];
    fu(i, 1, n){
        dp[i][1][1] = max(dp[i - 1][0][1], dp[i - 1][0][2]) + B[i];
        dp[i][1][2] = dp[i - 1][1][1] + B[i];
        dp[i][0][1] = max(dp[i - 1][1][1], dp[i - 1][1][2]) + A[i];
        dp[i][0][2] = dp[i - 1][0][1] + A[i];
    }
    cout << max(max(dp[n][1][1], dp[n][1][2]), max(dp[n][0][1], dp[n][0][2]));
}