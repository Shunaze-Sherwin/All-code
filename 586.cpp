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
const int mx = 10;

int n, m, x, y;
int A[mx + 5][mx + 5], B[mx + 5][mx + 5];

bool check(int a, int b){
	fu(i, 1, x)
		fu(j, 1, y)
			if (B[i][j] != A[a + i - 1][b + j - 1]) return false;
	return true;
}

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

	cin >> n >> m >> x >> y;
	fu(i, 1, n)
		fu(j, 1, m) cin >> A[i][j];
	fu(i, 1, x)
		fu(j, 1, y) cin >> B[i][j];
	fu(i, 1, n - x + 1)
		fu(j, 1, m - y + 1)
			if (check(i, j)){
				cout << "YES";
				return 0;
			}
	cout << "NO";
}