#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ld long double
#define ull unsigned ll
#define pa pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define gcd __gcd
#define log __lg
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define all(a) a.begin(), a.end()
#define fu(i,a,b) for (int i = (int)a; i <= (int)b; ++i)
#define fd(i,a,b) for (int i = (int)a; i >= (int)b; --i)
#define int ll

const int mod = 1e9 + 7;
const int mx = 2e5;

ll mulmod(ll a, ll b){
    if (b == 0) return 1;
    ll x = mulmod(a, b/2);
    if (b & 1) return x*x%mod*a%mod;
    return x*x%mod;
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

    int n;
    cin >> n;
    ll ans = 1;
    fu(i, 1, min(n, 3ll))
        ans *= 3 + (i%3 == 0);
    n -= min(3ll, n);
    ans = (ans*mulmod(3*3*4, n/3))%mod;
    n %= 3;
    fu(i, 1, n) ans = (ans*3)%mod;
    cout << ans;
}