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

vector<pa> v[mx + 5];
ll cost[mx + 5];
ll ans[mx + 5];

int n, m;

void di(int vt){
	fill(ans, ans + mx + 1, inf);
	fill(cost, cost + mx + 1, inf);
	cost[vt] = 0;
	ans[vt] = 0;
	priority_queue<pa, vector<pa>, greater<pa>> qu;
	qu.push({0, vt});
	while (!qu.empty()){
		pa temp = qu.top();
		qu.pop();
		if (temp.fi > cost[temp.se]) continue;
		for (pa i : v[temp.se])
			if (cost[i.fi] > temp.fi + 1){
				cost[i.fi] = temp.fi + 1;
				ans[i.fi] = i.se;
				qu.push({cost[i.fi], i.fi});
			}
			else 
				if ((cost[i.fi] == temp.fi + 1) && (ans[i.fi] > i.se)){
					ans[i.fi] = i.se;
					qu.push({cost[i.fi], i.fi});
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

	cin >> n >> m;
	fu(i, 1, m){
		int l, r, val;
		cin >> l >> r >> val;
		v[l].eb(r, val);
		v[r].eb(l, val);
	}
	di(n);
	cout << cost[1] << endl;
	ll mi = cost[1];
	ll vt = 1;
	vector<int> res;
	while (mi){
		--mi;
		for (pa i : v[vt])
			if (ans[vt] == i.se && cost[i.fi] == mi){
				res.eb(ans[vt]);
				vt = i.fi;
				break;
			}
	}
	for (int i : res) cout << i << char(32);
}