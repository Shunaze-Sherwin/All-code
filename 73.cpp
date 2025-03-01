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
#define gcd __gcd
#define log __lg
#define endl '\n'
#define lower lower_bound
#define upper upper_bound
#define search binary_search
#define all(a) a.begin(), a.end()
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)

const int mod = 1e9 + 7;
const int mx = 3e3;

bool vi[2*mx + 5][2*mx + 5] = { };
ll kt[2*mx + 5][2*mx + 5] = { };
ll A[mx + 5][mx + 5];

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

	int n, k;
	cin >> n >> k;
	fu(i, 1, n)
		fu(j, 1, n){
			int x;
			cin >> x;
			int a = i - j + n + 1;
			int b = i + j;
			vi[a][b] = true;
			if (x == 0) continue;
			int x1 = max(1, a - k);
			int y1 = max(1, b - k);
			int x2 = min(2*n, a + k);
			int y2 = min(2*n, b + k);
			kt[x1][y1] += x;
			kt[x2 + 1][y1] -= x;
			kt[x1][y2 + 1] -= x;
			kt[x2 + 1][y2 + 1] += x;
		}
	int ans = 0;
	fu(i, 1, 2*n)
		fu(j, 1, 2*n){
			kt[i][j] += kt[i - 1][j] + kt[i][j - 1] - kt[i - 1][j - 1];
			if (vi[i][j]){
				int a = (i + j - n - 1)/2;
				int b = j - a;
				A[a][b] = kt[i][j];
			}
		}
	fu(i, 1, n){
		fu(j, 1, n) cout << A[i][j] << char(32);
		cout << endl;
	}
}