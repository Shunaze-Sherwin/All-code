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
ll cost[mx + 5][15];
int n, m, k;

void bfs(int vt){
	cost[1][0] = 0;
	queue<int> qu;
	qu.push(vt);
	while (!qu.empty()){
		int temp = qu.front();
		qu.pop();
		for (int i : v[temp]){
			bool kt = false;
			fu(j, 0, k)
				if (cost[i][(j + 1)%k] > cost[temp][j] + 1){
					cost[i][(j + 1)%k] = cost[temp][j] + 1;
					kt = true;
				}
			if (kt) qu.push(i);
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

	cin >> n >> m >> k;
	fu(i, 1, m){
		int l, r;
		cin >> l >> r;
		v[l].eb(r);
		v[r].eb(l);
	}
	fu(i, 1, mx) fill(cost[i], cost[i] + 16, inf);
	bfs(1);
	cout << (cost[n][0] == inf ? -1 : cost[n][0]/k);
}