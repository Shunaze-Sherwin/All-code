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
	vector<int> v1;
	vector<int> v2;
	int A[n + 1];
	int ma = -1;
	fu(i, 1, n) {
		cin >> A[i];
		if (A[i] < 0) v1.pb(A[i]);
		else v2.pb(A[i]);
	}
	int i = 0;
	while (i < v1.size() || i < v2.size()){
		if (i < v1.size()) cout << v1[i] << char(32);
		if (i < v2.size()) cout << v2[i] << char(32);
		++i;
	}
}