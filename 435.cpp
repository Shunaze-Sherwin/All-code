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

const int mx = 500;
const int mod = 1e9 + 7;

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

	ll x, y;
	cin >> x >> y;
	string s;
	cin >> s;
	map<ll, int> D;
	ll de = 0;
	int d0 = 0, d1 = 0;
	++D[0];
	fu(i, 0, s.size() - 1){
		if (s[i] == '0') ++d0;
		else ++d1;
		ll val = d0*y - d1*x;
		de += D[val];
		++D[val];
	}
	cout << de;
}