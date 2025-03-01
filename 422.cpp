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
	int A[n + 1];
	fu(i, 1, n) cin >> A[i];
	int l, r;
	cin >> l >> r;
	//check 1
	int t1 = 0;
	int x = l, y = r;
	while (x != y){
		t1 += A[x];
		++x;
		if (x == n + 1) x = 1;
	}
	//check 2
	int t2 = 0;
	x = l, y = r;
	--x;
	if (x == 0) x = n;
	while (x != y){
		t2 += A[x];
		--x;
		if (x == 0) x = n;
	}
	t2 += A[x];
	cout << min(t1, t2);
}