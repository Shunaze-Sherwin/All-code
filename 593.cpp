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
int color[mx + 5] =  { };
int cost[mx + 5] = { };

struct gt{
	int u, val, c;
};

void bfs(gt pol){
	queue<gt> qu;
	qu.push(pol);
	if (!color[pol.u]) color[pol.u] = pol.c;
	while (!qu.empty()){
		gt temp = qu.front();
		qu.pop();
		if (temp.val > 0 && cost[temp.u] > temp.val) continue;
		for (int i : v[temp.u]){
			if (cost[i] < temp.val - 1){
				if (!color[i]) color[i] = temp.c;
				cost[i] = temp.val - 1;
				qu.push({i, cost[i], temp.c});
			}
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

	int n, m;
	cin >> n >> m;
	fu(i, 1, m){
		int l, r;
		cin >> l >> r;
		v[l].eb(r);
		v[r].eb(l);
	}
	int q;
	cin >> q;
	stack<gt> st;
	while (q--){
		int u, c, val;
		cin >> u >> val >> c;
		st.push({u, val, c});
	}
	fill(cost, cost + mx, -1);
	while (!st.empty()){
		bfs(st.top());
		st.pop();
	}
	fu(i, 1, n) cout << color[i] << endl;
}