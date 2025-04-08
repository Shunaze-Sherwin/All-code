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

int par[mx + 5];

struct gt{
	int u, v, w;
};

bool com(gt a, gt b){
	return a.w < b.w;
}

int find(int u){
	if (par[u] != u)  return par[u] = find(par[u]);
	return u;
}

bool join(int u, int v){
	int a = find(u), b = find(v);
	if (a != b) {
		par[b] = a;
		return true;
	}
	return false;
}

vector<gt> v;

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

	int n, m;
	cin >> n >> m;
	fu(i, 1, m){
		int l, r, val;
		cin >> l >> r >> val;
		v.push_back({l, r, val});
	}
	fu(i, 1, n) par[i] = i;
	sort(all(v), com);
	ll ans = 0;
	for (gt i : v)
		if (join(i.u, i.v)) ans += i.w;
	cout << ans;
}