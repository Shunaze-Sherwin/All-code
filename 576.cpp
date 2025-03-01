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
#define reset(a, k) memset(a, k, sizeof(a))  
#define fu(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define fillArr(A, l, r, val) fill(A + l, A + r + 1, val)
#define int ll

const int MOD = 1e9 + 7;
const int mx = 1e3;
const ll inf = 1e18 + 15;

int dp[mx + 5];
map<ll, ll> D;

bool check(int x) {
    return (x < (x / 2 + x / 3 + x / 4));
}

int dequy(int n) {
    if (D.find(n) != D.end()) return D[n];
    if (!check(n)) {
        D[n] = n;
        return n;
    }
    D[n] = dequy(n / 2) + dequy(n / 3) + dequy(n / 4);
    return D[n]; 
}

signed main() {
    #define FILE_NAME "Sherwin"
    if (fopen(FILE_NAME ".INP", "r")) {
        freopen(FILE_NAME ".INP", "r", stdin);
        freopen(FILE_NAME ".OUT", "w", stdout);
    }
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dequy(n) << endl;
    }
    return 0;
}