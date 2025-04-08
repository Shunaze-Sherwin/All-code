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
const int mx = 5e2;

int par[mx + 5];
int cost[mx + 5];
ll t = 0;

struct gt{
	int u, v, val;
};

vector<gt> tmp;

bool com(gt a, gt b){
	return a.val < b.val;
}

int find(int u){
	if (u == par[u]) return u;
	return par[u] = find(par[u]);
}

bool join(int u, int v){
	int a = find(u), b = find(v);
    if (a < b) swap(a, b);
	if (a != b){
		par[b] = a;
		return true;
	}
	return false;
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
	fu(i, 1, n) cin >> cost[i];
	fu(i, 1, n)
		fu(j, 1, n){
			int val;
			cin >> val;
			tmp.pb({i, j, val});
		}
	fu(i, 0, n) par[i] = i;
	fu(i, 1, n) tmp.pb({0, i, cost[i]});
	sort(all(tmp), com);
	ll ans = 0;
	for (gt i : tmp)
		if (join(i.u, i.v)) ans += i.val;
	cout << ans;
}