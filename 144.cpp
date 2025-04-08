#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ull unsgined ll
#define pa pair<int, int>
#define fi first
#define se second
#define pb pop_back
#define mp make_pair
#define em emplace_pack
#define endl '\n'
#define gcd __gcd
#define log __lg
#define all(a) a.begin(), a.end()
#define upper upper_bound
#define lower lower_bound
#define search binary_seach
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)

const int mod = 1e9 + 7;
const int mx = 1e3;

ll A[mx + 5], B[mx + 5];
ll dp[mx + 5][mx + 5] = { };

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
	fu(i, 1, n)
		fu(j, 1, n) 
			if (A[i] == B[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	cout << dp[n][n];
}