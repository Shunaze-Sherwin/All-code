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
const int mx = 5e3;
const ll inf = 1e18 + 15;

int A[mx + 5], B[mx + 5];
ll T[mx + 1][mx + 1] = { };

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

    int n;
    cin >> n;
    fu(i, 1, n) cin >> A[i];
    fu(i, 1, n) cin >> B[i];
    fu(i, 1, n)
        fu(j, 1, n)
            T[i][j] = T[i - 1][j - 1] + 1ll*A[i]*B[j];
    ll ans = -inf;
    fu(i, 1, n)
        fu(j, 1, n) {
            ans = max(ans, T[i][j] - T[i - 1][j - 1]);
            T[i][j] = min(T[i][j], T[i - 1][j - 1]);
        }
    cout << ans;
}