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

const int mod = 1e9 + 7;
const int mx = 5e6;

ll A[mx + 5];
ll n, k;
bool kt = false;

void dequy(int vt, ll t){
	if (t >= k){
		if (t == k) kt = true;
		return ;
	}
	if (vt > n) return ;
	dequy(vt + 1, t + A[vt]);
	dequy(vt + 1, t);
}

signed main(){

 	#define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

	#define name "CAU2"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	fu(i, 1, n) cin >> A[i];
	dequy(1, 0);
	if (kt) cout << "YES";
	else cout << "NO";
}