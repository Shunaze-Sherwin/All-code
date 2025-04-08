#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ld long double
#define ull unsigned ll
#define pa pair<int, int>
#define fi first
#define se second
#define pb pop_back
#define eb emplace_back
#define mp make_pair
#define endl '\n'
#define gcd __gcd
#define log __lg
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define all(a) a.begin(), a.end()
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)

const int mod = 1e9 + 7;
const int mx = 5e2;

ll A[mx + 5], T[mx + 5];
ll dp[mx + 5][mx + 5];

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
	fu(i, 1, n) T[i] = T[i - 1] + A[i];
	fu(i, 1, n) fill(dp[i], dp[i] + n + 1, inf);
	fd(i, n, 1)
		fu(j, i, n){
			if (i == j){
				dp[i][j] = 0;
				continue;
			}
			fu(k, i, j - 1)	dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (T[k] - T[i - 1]) + (T[j] - T[k]));
		}
	cout << dp[1][n];
}