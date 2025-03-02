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

int A[mx + 5] = { };
ll T[mx + 5];
ll L[mx + 5], R[mx + 5];
ll Ml[mx + 5];

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
	fu(i, 1, n) cin >> A[i];
	T[0] = 0;
	fu(i, 1, n) T[i] = T[i - 1] + A[i];

	ll mi = 0;
	Ml[0] = -inf;
	fu(i, 1, n){
		Ml[i] = max(Ml[i - 1], T[i] - mi); 
		mi = min(mi, T[i]); 
	}
	
	L[0] = 0;
	ll ma = 0;
	fu(i, 1, n){
		L[i] = max(L[i - 1], T[i] + ma); 
		ma = max(ma, Ml[i] - T[i]); 
	}

	R[n + 1] = -inf;
    ma = T[n];
	fd(i, n, 1){
        ma = max(ma, T[i]);
		R[i] = max(R[i + 1], ma - T[i - 1]);
	}

	ma = -inf;
	fu(i, 1, n) ma = max(ma, L[i] + R[i + 1]);
	cout << ma;
}