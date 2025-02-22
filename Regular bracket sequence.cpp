#include <bits/stdc++.h>

using namespace std;

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
#define up upper_bound
#define low lower_bound
#define all(a) (a).begin(), (a).end()
#define bit(i, mask) ((mask) & (1 << (i)))
#define reset(a, k) memeset(all(a), k, sizeof(a))
#define fu(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define fill(A, l, r, val) fill(A + l, A + r + 1, val)

const int MOD = 1e9 + 7;
const int mx = 1e3;
const ll inf = 1e18 + 15;

int dp[mx + 5][mx + 5];

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "BAI5"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    dp[0][0] = 1;
    fu(i, 1, n)
        if (s[i] == '(')
            fu(j, 1, n) dp[i][j] = dp[i - 1][j - 1];
        else
        if (s[i] == ')')
            fu(j, 0, n - 1) dp[i][j] = dp[i - 1][j + 1];
        else{
            dp[i][0] = dp[i - 1][1];
            dp[i][n] = dp[i - 1][n - 1];
            fu(j, 1, n - 1) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%MOD;
        }
    cout << dp[n][0];
}