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

const int mx = 5e2;
const int mod = 1e9 + 7;

ll dp[mx + 5][mx + 5] = { };

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

	int a, b;
	cin >> a >> b;
	fu(i, 1, a)
		fu(j, 1, b){
			if (i == j){
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = inf;
			fu(k, 1, i - 1) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
			fu(k, 1, j - 1) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
		}
	cout << dp[a][b];
}