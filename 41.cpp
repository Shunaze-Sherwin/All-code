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
#define int ll

const int mod = 1e9 + 7;
const int mx = 1e5;
const int sm = 1e6;

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

	int n, m, q;
	cin >> n >> m >> q;
	int A[n + 1][m + 1];
	fu(i, 1, n)
		fu(j, 1, m) cin >> A[i][j];
	while (q--){
		int c, l, r;
		cin >> c >> l >> r;
		if (c == 1)
			fu(i, 1, m) swap(A[l][i], A[r][i]);
		if (c == 2)
			fu(i, 1, n) swap(A[i][l], A[i][r]);
	}
	fu(i, 1, n){
		fu(j, 1, m) cout << A[i][j] << char(32);
		cout << endl;
	}
}