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
const int sm = 1e6;

bool SG[sm + 5];

ll lcm(ll a, ll b){
	return a*b/gcd(a, b);
}

bool nto(ll a){
	if (a < 2) return false;
	for (int i = 2; i*i <= a; ++i)
		if (a%i == 0) return false;
	return true;
}

void sang(){
	memset(SG, true, sizeof(SG));
	SG[0] = false;
	SG[1] = false;
	for (int i = 2; i*i <= sm; ++i)
		if (SG[i]){
			int j = i*i;
			while (j <= sm){
				SG[j] = false;
				j += i;
			}
		}
}

ll mulmod(ll a, ll b){
	ll ans = 0;
	a %= mod;
	while (b){
		if (b & 1) ans = (ans + a)%mod;
		b /= 2;
		a = (a*2)%mod;
	}
	return ans;
}

signed main(){

 	#define name "test"
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

	int n, q;
	cin >> n >> q;
	int A[n + 1];
	fu(i, 1, n) cin >> A[i];
	int L[q + 1], R[q + 1];
	fu(i, 1, q) cin >> L[i] >> R[i];
	fd(i, q, 1) swap(A[L[i]], A[R[i]]);
	fu(i, 1, n) cout << A[i] << char(32);
}