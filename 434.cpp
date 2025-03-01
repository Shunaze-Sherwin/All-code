#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ull unsigned long long
#define pa pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define gcd __gcd
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define fu(i,a,b) for (int i = a; i <= b; ++i)
#define fd(i,a,b) for (int i = a; i >= b; --i)
#define all(a) a.begin(), a.end()

const int mod = 1e9 + 7;
const int mx = 1e5;

signed main(){

 	#define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

	#define name "GT"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int A[n + 1][m + 1];
	fu(i, 1, n)
		fu(j, 1, m) cin >> A[i][j];
	vector<int> v[n + m];
	fu(i, 1, m){
		int x = 1, y = i;
		while (y > 0 && x <= n){
			v[i].pb(A[x][y]);
			--y;
			++x;
		}
	}
	fu(i, 2, n){
		int x = i, y = m;
		while (x <= n && y > 0){
			v[m + i - 1].pb(A[x][y]);
			++x;
			--y;
		}
	}
	fu(i, 1, m + n - 1)
		if (i & 1)
			fd(j, v[i].size() - 1, 0) cout << v[i][j] << char(32);
		else 
			for (int j : v[i]) cout << j << char(32);
}