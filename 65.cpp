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

ll A[mx + 5], T1[2*mx + 5], T2[2*mx + 5];

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

	int n;
	cin >> n;
	T1[0] = 0;
	T2[0] = 0;
	fu(i, 1, n) {
		cin >> A[i];
		A[n + i] = A[i];
		T1[i] = T1[i - 1] + A[i];
		T2[i] = T2[i - 1] + A[i]*i;
	}
	fu(i, n + 1, 2*n){
		T1[i] = T1[i - 1] + A[i - n];
		T2[i] = T2[i - 1] + A[i - n]*i;
	}
	ll mi = inf;
	fu(i, 1, n){
		int m = i + n - 1;
		int mid = (m + i)/2;
		ll val1 = mid*(T1[mid - 1] - T1[i - 1]) - T2[mid - 1] + T2[i - 1];
		ll val2 = T2[m] - T2[mid] - mid*(T1[m] - T1[mid]);
		mi = min(mi, val1 + val2);
	}
	cout << mi;
}