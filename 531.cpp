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

int CN[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(ll y){
	if (y%400 == 0) return true;
	if (y%100 == 0) return false;
	if (y%4 == 0) return true;
	return false;
}

signed main(){

 	#define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

	#define name "CAU5"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	ll x, d, m, y;
	cin >> x >> d >> m >> y;
	
	ll val = x/(303*365 + 97*366);
	y += val*400;
	x %= 303*365 + 97*366;
	while (x--){
		++d;
		int val = CN[m] + (check(y) && m == 2);
		if (d > val){
			d = 1;
			++m;
		}
		if (m > 12){
			m = 1;
			++y;
		}
	}
	cout << d << char(32) << m << char(32) << y;
}