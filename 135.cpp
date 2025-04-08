#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ull unsigned ll
#define pa pair<int, int>
#define fi first
#define se second
#define pb push_back
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

int par[mx + 5];
int h[mx + 5];
bool vi[mx + 5] = { };
int color[mx + 5] = { };
vector<int> v[mx + 5];

void dfs(int u){
	vi[u] = true;
	for (int i : v[u])
		if (!vi[i]){
			par[i] = u;
			h[i] = h[u] + 1;
			dfs(i);
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

	int n, q;
	cin >> n >> q;
	fu(i, 1, n - 1){
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	par[1] = 1, h[1] = 0;
	dfs(1);
	while (q--){
		int u, v, c;
		cin >> u >> v >> c;
		vector<int> res;
		if (!color[u]) color[u] = c;
		while (h[v] > h[u]){
			if (!color[v]) color[v] = c;
			res.pb(v);
			v = par[v];
		}
		for (int v : res) par[v] = u;
	}
	fu(i, 1, n) cout << color[i] << char(32);
}