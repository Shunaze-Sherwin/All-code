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
const int mx = 1e3;

int A[mx + 5][mx + 5];

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

	int n, m, q;
	cin >> n >> m >> q;
	while (q--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		++A[a][b];
		--A[a][d + 1];
		--A[c + 1][b];
		++A[c + 1][d + 1];
	}
	fu(i, 1, n){
		fu(j, 1, m){
			A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
			cout << A[i][j] << char(32);
		}
		cout << endl;
	}
}