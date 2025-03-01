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
const int mx = 1e6;

pa T[mx + 5] = { };

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

	string s;
	cin >> s;
	map<int, int> D;
	s = " " + s;
	++D[0];
	fu(i, 1, s.size() - 1){
		T[i] = T[i - 1];
		if (s[i] == '0') ++T[i].fi;
		else ++T[i].se;
		++D[T[i].fi - T[i].se];
	}
	ll de = 0;
	fu(i, 0, s.size() - 1){
		--D[T[i].fi - T[i].se];
		de += D[T[i].fi - T[i].se];
	}
	cout << de;
}