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

const int mx = 2e3;
const int mod = 1e9 + 7;

pair<char, ll> dp[10];

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

	string s;
	cin >> s;
	string temp = "marisa";
	fu(i, 0, temp.size() - 1) dp[i + 1] = {temp[i], 0};
	dp[0].se = 1;
	fu(i, 0, s.size() - 1)
		fu(j, 1, 6)
			if (s[i] == dp[j].fi) dp[j].se = (dp[j].se + dp[j - 1].se)%mod;
	cout << dp[temp.size()].se;
}