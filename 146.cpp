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
const int sm = 2e3;

bool SG[sm + 5];
ll dp[mx + 5][mx + 5] = { };

void sang(){
	memset(SG, true, sizeof(SG));
	SG[0] = SG[1] = false;
	for (int i = 2; i*i <= sm; ++i)
		if (SG[i]){
			int j = i*i;
			while (j <= sm){
				SG[j] = false;
				j += i;
			}
		}
}

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

	sang();
	int n, k;
	cin >> n >> k;
	fu(i, 0, k) dp[1][i] = (n == 1 ? SG[i] : 1);
	fu(i, 2, n)
		fu(j, 0, k)
			fu(u, 0, k)
				if (SG[j + u]) dp[i][j] = (dp[i][j] + dp[i - 1][u])%mod;
	ll ans = 0;
	fu(i, 0, k) ans = (ans + dp[n][i])%mod;
	cout << ans;
}