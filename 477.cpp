#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ld long double
#define ull unsigned ll
#define pa pair<int, int>
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

const int mod = 1e9;
const int mx = 1e5;

map<ll, ll> D;
set<ll> s;

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
    while (q--){
        int c;
        cin >> c;
        if (c == 1){
            ll val, a;
            cin >> val >> a;
            D[val] += a;
            s.insert(val);
        }
        if (c == 2){
            ll val, b;
            cin >> val >> b;
            D[val] -= min(D[val], b);
            if (D[val] == 0) s.erase(val);
        }
        if (c == 3) cout << *s.begin() << endl;
        if (c == 4) cout << *s.rbegin() << endl;
        if (c == 5){
            ll val;
            cin >> val;
            auto t1 = s.lower(val), t2 = s.upper(val);
            int kq1 = 1, kq2 = 1;
            if (t1 == s.begin()) kq1 = 0;
            else --t1;
            if (t2 == s.end()) kq2 = 0;
            cout << D[val]*val + (kq1 == 0 ? 0 : D[*t1]*(*t1)) + (kq2 == 0 ? 0 : D[*t2]*(*t2)) << endl;
        }
    }
}