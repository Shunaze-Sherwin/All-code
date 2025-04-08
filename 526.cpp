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
const int mx = 5e2;

char A[mx + 5][mx + 5];
bool vi[mx + 5][mx + 5] = { };
int L[] = {1, 0, 0, -1};
int R[] = {0, 1, -1, 0};
int n, m;

bool check(int a, int b){
	fu(i, 0, 3){
		int x = a + L[i];
		int y = b + R[i];
		if (x < 1 || y < 1 || x > n || y > m) continue;
		if (A[x][y] == '.') return false;
	}
	return true;
}

int bfs(int a, int b){
	queue<pa> qu;
	qu.push({a, b});
	vi[a][b] = true;
	int res = 1;
	while (!qu.empty()){
		pa temp = qu.front();
		qu.pop();
		if (!check(temp.fi, temp.se)) res = -1e5;
		fu(i, 0, 3){
			int x = temp.fi + L[i];
			int y = temp.se + R[i];
			if (x < 1 || y < 1 || x > n || y > m || vi[x][y]) continue;
			vi[x][y] = true;
			if (A[x][y] == 'W') ++res, qu.push({x, y});
		}
	}
	return max(res, 0);
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
	fu(i, 1, n)
		fu(j, 1, m) cin >> A[i][j];
	ll ans = 0;
	fu(i, 1, n)
		fu(j, 1, m)
			if (!vi[i][j] && A[i][j] == 'W') ans += bfs(i, j);
	cout << ans;
}