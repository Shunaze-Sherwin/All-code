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
int sl[mx + 5];
int ans[mx + 5];
bool D[mx + 5];
pa Q[mx + 5];

int find(int u){
	if (u != par[u]) return par[u] = find(par[u]);
	return u;
}

void join(int u, int v){
	int a = find(u), b = find(v);
	if (a != b) par[b] = a, sl[a] += sl[b];
}

vector<pa> v;

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

	int n, m, q;
	cin >> n >> m >> q;
	fu(i, 1, m){
		int l, r;
		cin >> l >> r;
		v.pb({l, r});
	}
	fu(i, 1, n) par[i] = i, sl[i] = 1;
	fill(D, D + mx + 1, true);
	fu(i, 1, q){
		cin >> Q[i].fi >> Q[i].se;
		D[Q[i].fi] = false;
	}
	fu(i, 1, m)
		if (D[i]){
			join(v[i - 1].fi, v[i - 1].se);
		}
	fd(i, q, 1){
		ans[i] = sl[find(Q[i].se)];
		int vt = Q[i].fi;
		join(v[vt - 1].fi, v[vt - 1].se);
	}
	fu(i, 1, q) cout << ans[i] << endl;
}