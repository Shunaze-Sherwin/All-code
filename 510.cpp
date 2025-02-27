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
#define int ll

const int MOD = 1e9 + 7;
const int mx = 1e3;
const ll inf = 1e18 + 15;

int dp[mx + 5];

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "BAI1"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    reverse(all(s));
    s = " " + s;
    dp[0] = 1;
    fu(i, 1, n)
        fu(j, 0, 9)
            fu(k, 0, 9){
                if (j + k == s[i] - '0') dp[i] += dp[i - 1];
                if (i > 1 && s[i] != '0' && j + k == (s[i] - '0')*10 + (s[i - 1] - '0')) 
                    dp[i] += dp[i - 2];
            }
    cout << dp[n];
}