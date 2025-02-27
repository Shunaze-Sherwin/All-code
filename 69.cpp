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

bool SG[sm + 5];
int A[mx + 5] = { };

bool nto(int a){
	if (a < 2) return false;
	for (int i = 2; i*i <= a; ++i)
		if (a%i == 0) return false;
	return true;
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

void sang(){
	memset(SG, true, sizeof(SG));
	SG[1] = false;
	SG[0] = false;
	for (int i = 2; i*i <= sm; ++i)
		if (SG[i]){
			int j = i*i;
			while (j <= sm){
				SG[j] = false;
				j += i;
			}
		}
}

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

	int n, q;
	cin >> n >> q;
	fu(i, 1, q){
		int l, r;
		cin >> l >> r;
		++A[l], --A[r + 1];
	}
	int t = 0;
	fu(i, 1, n){
		t += A[i];
		cout << t << char(32);
	}
}