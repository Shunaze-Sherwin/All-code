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
const int mx = 1e5;
const int sm = 1e6;

ll A[mx + 5] = { };
int B[mx + 5] = { };
pa Q[mx + 5];

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

	int n, q, m;
	cin >> n >> q >> m;
	fu(i, 1, q) cin >> Q[i].fi >> Q[i].se;
	while (m--){
		int l, r;
		cin >> l >> r;
		++B[l];
		--B[r + 1];
	}
	fu(i, 1, q) {
		B[i] += B[i - 1];
		A[Q[i].fi] += B[i];
		A[Q[i].se + 1] -= B[i];
	}
	fu(i, 1, n){
		A[i] += A[i - 1];
		cout << A[i] << char(32);
	}
}