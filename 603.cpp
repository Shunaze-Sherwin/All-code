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
const int mx = 2e5;

ll A[mx + 5] = { }, B[mx + 5] = { };
ll ans = 0;
ll n, q, s, t;

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

	cin >> n >> q >> s >> t;
	fu(i, 0, n) cin >> B[i];
	A[0] = 0;
	fu(i, 0, n - 1) A[i] = B[i] - B[i + 1];
	fu(i, 0, n - 1)
		if (A[i] < 0) ans += s*A[i]; 
		else ans += t*A[i];	
	while (q--){
		ll l, r, x;
		cin >> l >> r >> x;

		if (A[l - 1] < 0) ans -= s*A[l  - 1];
		else ans -= t*A[l - 1];
		A[l - 1] -= x;
		if (A[l - 1] < 0) ans += s*A[l - 1];
		else ans += t*A[l - 1];
		
		if (A[r] < 0) ans -= s*A[r];
			else ans -= t*A[r];

		if (r < n){
		    A[r] += x;
			if (A[r] < 0) ans += s*A[r];
			else ans += t*A[r];
        }
		cout << ans << endl;
	}
}