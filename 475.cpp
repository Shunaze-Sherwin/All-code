#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ld long double
#define ull unsigned ll
#define pa pair<ll,ll>
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

multiset<int> s;

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
        int c, val;
        cin >> c >> val;
        if (c == 1) s.insert(val);
        if (c == 2) {
            auto vt = s.find(val);
            if (vt != s.end()) s.erase(vt);
        }
        if (c == 3){
            auto vt = s.upper(val);
            cout << (vt == s.end() ? -1 : *vt) << endl;
        }
        if (c == 4){
            auto vt = s.upper(val);
            cout << (vt == s.begin() ? -1 : *(--vt)) << endl;
        }
    }
}