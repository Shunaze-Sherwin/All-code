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

int ans[mx + 5], par[mx + 5], sl[mx + 5];
pa A[mx + 5], Q[mx + 5];
bool D[mx + 5] = { };
int res = 0;

int find(int u){
	if (u == par[u]) return u;
	return par[u] = find(par[u]);
}

void join(int u, int v){
	int a = find(u), b = find(v);
	if (a != b) {
		par[b] = a, sl[a] += sl[b];
		res = max(res, sl[a]);
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
	fu(i, 1, n) {
		cin >> A[i].fi;
		A[i].se = i;
	}
	sort(A + 1, A + n + 1);
	fu(i, 1, q){
		cin >> Q[i].fi;
		Q[i].se = i;
	}
	sort(Q + 1, Q + q + 1);
	fu(i, 1, n) par[i] = i, sl[i] = 1;
	int vt = 1;
	fu(i, 1, q){
		while (vt <= n && A[vt].fi <= Q[i].fi){
			res = max(res, 1);
			int val = A[vt].se;
			D[val] = true;
			int a = val - 1, b = val + 1;
			if (a > 0 && D[a]) join(a, val);
			if (b <= n && D[b]) join(val, b);
			++vt;
		}
		ans[Q[i].se] = res;
	}
	fu(i, 1, q) cout << ans[i] << endl;
}