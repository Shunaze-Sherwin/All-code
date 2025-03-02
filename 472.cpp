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

const int mx = 2e5;
const int mod = 1e9 + 7;

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
    vector<ll> v;
    v.pb(0);
    fu(i, 1, n){
        ll x;
        cin >> x;
        v.pb(v.back() + x);
    }
    while (q--){
        int c;
        cin >> c;
        if (c == 2) v.pop_back();
        if (c == 1){
            ll x;
            cin >> x;
            v.pb(v.back() + x);
        }
        if (c == 3){
            int l, r;
            cin >> l >> r;
            cout << v[r] - v[l - 1] << endl;
        }
    }
}