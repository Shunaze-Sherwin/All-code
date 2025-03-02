#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ull unsigned ll
#define pa pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define log __lg
#define gcd __gcd
#define endl '\n'
#define lower lower_bound
#define upper upper_bound
#define search binary_search
#define all(a) a.begin(), a.end()
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)

const int mx = 1e6;
const int mod = 1e9 + 7;
const int sm = 1e6;

pa A[mx + 5];
ll B[mx + 5];
priority_queue<int> qu;

bool com(int a, int b){
    return a > b;
}

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "W", stdout);
    }

    #define name "DINER"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "W", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, q;
	cin >> n >> q;
	fu(i, 1, n) cin >> A[i].fi >> A[i].se;
	ll ma = A[1].se*q + A[1].fi, vt = 1;
	fu(i, 1, n)
		if (ma < A[i].se*q + A[i].fi){
			ma = A[i].se*q + A[i].fi;
			vt = i;
		}
    int de = 0;
	fu(i, 1, n)
		if (i != vt){
            ++de;
            B[de] = A[i].fi + A[i].se;
        }
    sort(B + 1, B + de + 1, com);
	fu(i, 1, de){
        if (B[i] <= A[vt].se || i == q) break;
        ma -= A[vt].se;
        ma += B[i];
    }
	cout << ma;
}