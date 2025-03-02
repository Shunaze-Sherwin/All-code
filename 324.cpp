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
#define log __lg
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define fu(i,a,b) for (int i = a; i <= b; ++i)
#define fd(i,a,b) for (int i = a; i >= b; --i)
#define all(a) a.begin(), a.end()

const int mod = 1e9 + 7;
const int mx = 1e5;

bool kt = false;
int A[10][10] = { };
int n, m;
int X8[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int Y8[8] = {1, -1, 1, -1, 2, 2, -2, -2};

void dequy(int i, int j, int de){
	if(i < 1 || j < 1 || i > n || j > m || A[i][j] != 0) return ;
	A[i][j] = de;
	if (de == n*m) {
		kt = true;
		return ;
	}
	fu(k, 0, 7){
		int a = i + X8[k];
		int b = j + Y8[k];
		dequy(a, b, de + 1);
		if (kt) return ;
	}
	A[i][j] = 0;
}

signed main(){

 	#define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

	#define name "APROBOT"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	dequy(1, 1, 1);
	fu(i, 1, n){
		fu(j, 1, m) cout << A[i][j] << char(32);
		cout << endl;
	}
}