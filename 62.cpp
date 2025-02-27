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
#define int ll

const int mod = 1e9 + 7;
const int mx = 1e5;
const int sm = 1e6;

ll T[mx + 5];

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n, d;
	cin >> n >> d;
	map<int, int> D;
	T[0] = 0;
	++D[0];
	fu(i, 1, n){
		int x;
		cin >> x;
		x = (x%d + d)%d;
		T[i] = (T[i - 1] + x)%d;
		++D[T[i]];
	}
	ll de = 0;
	fu(i, 0, n){
		--D[T[i]%d];
		de += D[T[i]%d];
	}
	cout << de;
}