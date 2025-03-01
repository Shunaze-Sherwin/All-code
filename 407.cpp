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
const int mx = 1e2;

int A[mx + 5][mx + 5] = { };

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

	int n, m, val = 1;
	cin >> n >> m;
	int x = 1;
	while (x <= min(n, m)/2 + ((m + n) & 1)){
		fu(i, x, m - x){
			A[x][i] = val;
			if (val == n*m) break;
			++val;
		}
		if (val == n*m) break;
		fu(i, x, n - x){
			A[i][m - x + 1] = val;
			if (val == n*m) break;
			++val;
		}
		if (val == n*m) break;
		fd(i, m - x + 1, x + 1){
			A[n - x + 1][i] = val;
			if (val == n*m) break;
			++val;
		}
		if (val == n*m) break;
		fd(i, n - x + 1, x + 1){
			A[i][x] = val;
			++val;
		}
		++x;
	}
	fu(i, 1, n)
		fu(j, 1, m) 
			if (A[i][j] == 0){
				A[i][j] = val;
				++val;
			}
	fu(i, 1, n){
		fu(j, 1, m) cout << A[i][j] << char(32);
		cout << endl;
	}
}