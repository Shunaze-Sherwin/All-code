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
const int mx = 1e3;

int p[mx + 5];
ll cost[mx + 5][mx + 5];
vector<int> v[mx + 5];
vector<pa> tmp;
int vi[mx + 5] = { };

void bfs(int u){
	cost[u][u] = 0;
	queue<int> qu;
	qu.push(u);
	vi[u] = u;
	while (!qu.empty()){
		int temp = qu.front();
		qu.pop();
		for (int i : v[temp])
			if (vi[i] != u){
				vi[i] = u;
				cost[u][i] = cost[u][temp] + 1;
				qu.push(i);
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

	int n, m, k;
	cin >> n >> m >> k;
	fu(i, 1, k) cin >> p[i];
	fu(i, 1, m){
		int a, b;
		cin >> a >> b;
		v[a].eb(b);
		v[b].eb(a);
		tmp.eb(a, b);
	}
	fu(i, 1, k) bfs(p[i]);
	ll ans = inf;
	for (pa i : tmp){
		ll t = 0;
		fu(j, 1, k) t += min(cost[p[j]][i.fi], cost[p[j]][i.se]);
		ans = min(ans, t);
	}
	cout << ans;
}