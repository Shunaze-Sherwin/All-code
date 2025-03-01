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

bool L[mx + 5] = { }, R[mx + 5] = { };

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

	int n;
	cin >> n;
	int A[n + 1];
	fu(i, 1, n) cin >> A[i];
	L[1] = true;
	fu(i, 2, n)
		if (A[i - 1] < A[i]) L[i] = true;
		else break;
	R[n] = true;
	fd(i, n - 1, 1)
		if (A[i] > A[i + 1]) R[i] = true;
		else break;
	fu(i, 1, n)
		if (L[i] && R[i]){
			cout << "YES";
			return 0;
		}
	cout << "NO";
}