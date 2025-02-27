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

const int mod = 1e9 + 7;
const int mx = 2e5;

ll mulmod(ll a, ll b, ll c){
    ll ans = 0;
    while (b){
        if (b & 1) ans = (ans + a)%c;
        a = (a*2)%c;
        b /= 2;
    }
    return ans;
}

ll mulpow(ll a, ll b, ll c){
    if (b == 0) return 1;
    ll x = mulpow(a, b/2, c)%c;
    x = mulmod(x, x, c);
    if (b & 1) return mulmod(x, a, c);
    return x;
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

    ll a, b, c;
    cin >> a >> b >> c;
    a %= c;
    cout << mulpow(a, b, c);
}