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

bool dp[mx + 5][mx + 5] = { };

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
	fd(i, s.size() - 1, 0)
		fu(j, i, s.size() - 1){
			if (abs(i - j) <= 1 && s[i] == s[j]) {
				dp[i][j] = true;
				continue;
			}
			if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
		}
	int q;
	cin >> q;
	while (q--){
		int l, r;
		cin >> l >> r;
		cout << (dp[l - 1][r - 1] ? "YES" : "NO") << endl;
	}
}