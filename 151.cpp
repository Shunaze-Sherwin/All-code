#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ull unsigned ll
#define pa pair<int, int>
#define fi first
#define se second
#define pb pop_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define gcd __gcd
#define log __lg
#define all(a) a.begin(), a.end()
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define fu(i, a, b) for (int i = (int)a; i <= (int)b; ++i)
#define fd(i, a, b) for (int i = (int)a; i >= (int)b; --i)

const int mx = 1e5;
const int mod = 1e9 + 7;

int A[mx + 5];
ll dp[mx + 5];

signed main(){

	#define name "Sherwin"
	if (fopen(name".INP", "r")){
		freopen(name".INP", "r", stdin);
		freopen(name".OUT", "w", stdout);
	}

	#define name "Sherwin"
	if (fopen(name".INP", "r")){
		freopen(name".INP", "r", stdin);
		freopen(name".OUT", "w", stdout);
	}

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	fu(i, 1, n) cin >> A[i];
	fill(dp + 1, dp + k + 1, inf);
	dp[0] = 0;
	fu(i, 1, k)
		fu(j, 1, n)
			if (i >= A[j]) dp[i] = min(dp[i], dp[i - A[j]] + 1);
	cout << (dp[k] == inf ? -1 : dp[k]);
}