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
#define bit(i, mask) (mask & (1 << i))
#define reset(a, k) memeset(all(a), k, sizeof(a))
#define fu(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define fill(A, l, r, val) fill(A + l, A + r + 1, val)
#define int ll

const int MOD = 1e9 + 7;
const int mx = 5e3;
const ll inf = 1e18 + 15;

int A[mx + 5] = { };
int dp[mx + 5][mx + 5] = { };
int n;

bool check(int l, int r){
    if (n & 1) return ((r + l)%2 == 0);
    return (r + l)%2;
}

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

    cin >> n;
    int t = 0;
    fu(i, 1, n) {
        cin >> A[i];
        t += A[i];
    }
    fd(l, n, 1){
        fu(r, l, n){
            if (l == r){
                dp[l][r] = (check(l, r) ? A[l] : -A[l]);
                continue;
            }
            if (check(l, r)) dp[l][r] = max(dp[l + 1][r] + A[l], dp[l][r - 1] + A[r]);
            else dp[l][r] = min(dp[l + 1][r] - A[l], dp[l][r - 1] - A[r]);
        }
    }
    cout << dp[1][n];
}