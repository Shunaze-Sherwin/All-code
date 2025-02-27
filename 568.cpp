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
#define bin binary_search
#define all(a) (a).begin(), (a).end()
#define bit(i, mask) ((mask) & (1 << (i)))
#define reset(a) memset(all(a), 0, sizeof(a))
#define fu(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define fd(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define fill(A, l, r, val) fill(A + l, A + r + 1, val)
#define int ll

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

    #define name "swap"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    s = "%" + s;
    fd(i, n, 1)
        fu(j, i, n){
            if (i == j){
                dp[i][j] = 0;
                continue;
            }
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
            else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
    cout << dp[1][n];
}