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
const int mx = 1e3;

int n, m, x, y;
int A[mx + 5][mx + 5], B[mx + 5][mx + 5];

ll t1(int i, int j){
	int t = 0;
	while (i > 0 && j > 0){
		t += A[i][j];
		--i;
		--j;
	}
	return t;
}

ll t2(int i, int j){
	int t = 0;
	while (i <= n && j <= m){
		t += A[i][j];
		++i;
		++j;
	}
	return t;
}

ll t3(int i, int j){
	int t = 0;
	while (i > 0 && j <= m){
		t += A[i][j];
		--i;
		++j;
	}
	return t;
}

ll t4(int i, int j){
	int t = 0;
	while (i <= n && j > 0){
		t += A[i][j];
		++i;
		--j;
	}
	return t;
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
	cout << t1(x, y) + t2(x, y) + t3(x, y) + t4(x, y) - 3*A[x][y];
}