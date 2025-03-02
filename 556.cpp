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
#define all(a) a.begin(), a.end()
#define lower lower_bound
#define upper upper_bound
#define search binary_search
#define log __lg
#define gcd __gcd
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)

const int mx = 1e3;
const int mod = 1e9 + 7;
const int sm = 1e6;

pa A[mx + 5];

signed main(){

	#define name "Sherwin"
	if (fopen(name".INP", "r")){
		freopen(name".INP", "r", stdin);
		freopen(name".OUT", "w", stdout);
	}

	#define name "BOSO"
	if (fopen(name".INP", "r")){
		freopen(name".INP", "r", stdin);
		freopen(name".OUT", "w", stdout);
	}

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	ll t = 0;
	fu(i, 1, n) cin >> A[i].fi;
	fu(i, 1, n) {
		cin >> A[i].se;
		t += A[i].se;
	}
	sort(A + 1, A + n + 1);
	multiset<pa> s;
	fu(i, 1, n)
		if (A[i].fi > (int)s.size()) s.insert({A[i].se, A[i].fi});
		else
			if (A[i].se > (*s.begin()).fi){
				s.erase(s.begin());
				s.insert({A[i].se, A[i].fi});
			}
	ll ans = 0;
	for (pa val : s) ans += val.fi;
	cout << t - ans;
}