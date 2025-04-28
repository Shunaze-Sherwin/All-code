#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned ll
#define pa pair<ll, ll>
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
#define all(a) (a).begin(), (a).end()
#define fu(i,a,b) for (int i = (int)a; i <= (int)b; ++i)
#define fd(i,a,b) for (int i = (int)a; i >= (int)b; --i)

const int mod = 100;
const int mx = 5e2;
const ll inf = 1e18;

pa dp[mx + 5][mx + 5];
ll A[mx + 5];

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

    int q;
    cin >> q;
    ll val = 0;
    while (q--){
        int c, x;
        cin >> c >> x;
        if (c == 1) val = val | (1ll << x);
        if (c == 2) val = val & ~(1ll << x);
        if (c == 3) val = val ^ (1ll << x);
        cout << val << endl;
    }
}