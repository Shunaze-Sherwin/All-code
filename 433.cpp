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
const int mx = 5e6;

int X4[4] = {1, -1, 0, 0};
int Y4[4] = {0, 0, 1, -1};
int n, m;
char A[50 + 5][50 + 5];
string s;

bool check(int a, int b){
	fu(i, 0, 3){
		int x = a;
		int y = b;
		int de = 0;
		while (x > 0 && x <= n && y > 0 && y <= m && de < s.size()){
			if (s[de] == A[x][y]) ++de;
			else break;
			x += X4[i];
			y += Y4[i];
		}
		if (de == s.size()) return true;
	}
	return false;
}

signed main(){

 	#define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

	#define name "CAU2"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	fu(i, 1, n)
		fu(j, 1, m) cin >> A[i][j];
	cin >> s;
	fu(i, 1, n)
		fu(j, 1, m)
			if (check(i, j)){
				cout << "YES";
				return 0;
			}
	cout << "NO";
}