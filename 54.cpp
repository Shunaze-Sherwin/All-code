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
const int mx = 1e5;

int n, k;
int A[mx + 5], B[mx + 5];
ll ma = 0;

void dequy(int vt, ll t, ll w){
	if (w > k) return ;
	ma = max(ma, t);
	fu(i, vt, n){
		dequy(i + 1, t + A[i], w + B[i]);
		dequy(i + 1, t, w);
	}
}

signed main(){

 	#define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

	#define name "APROBOT"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	fu(i, 1, n) cin >> B[i] >> A[i];
	dequy(1, 0, 0);
	cout << ma;
}