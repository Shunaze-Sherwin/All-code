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
const int mx = 500;

ll A[mx + 5][mx + 5] = { };

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
	fu(i, 1, n)
		fu(j, 1, m){
			cin >> A[i][j];
			A[i][j] += A[i][j - 1];
		}
	ll ma = -inf;
	fu(i, 1, m)
		fu(j, i, m){
			ll t = 0;
			fu(k, 1, n){
				t += A[k][j] - A[k][i - 1];
				ma = max(ma, t);
				if (t < 0) t = 0;
			}
		}
	cout << ma;
}