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
const int mx = 1e5;

vector<int> v[mx + 5];
int ans[mx + 5] = { };
bool vi[mx + 5] = { };

void dfs(int vt){
	ans[vt] = 1;
	vi[vt] = true;
	for (int i : v[vt]) 
		if (!vi[i]){
			dfs(i);
			ans[vt] += ans[i];
		}
	if (ans[vt] == 0) ans[vt] = 1;
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

	int n;
	cin >> n;
	fu(i, 1, n - 1){
		int l, r;
		cin >> l >> r;
		v[l].eb(r);
		v[r].eb(l);
	}
	dfs(1);
	fu(i, 1, n) cout << ans[i] << char(32);
}