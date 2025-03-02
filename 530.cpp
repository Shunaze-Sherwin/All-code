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

set<int> s;
multiset<int> k;

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
        int p;
        cin >> p;
        auto vt = s.find(p);
        if (vt != s.end()){
            auto it1 = vt, it2 = vt;
            --it1;
            ++it2;
            if (vt != s.begin()) k.erase(k.find(p - *it1));
            if (it2 != s.end()) k.erase(k.find(*it2 - p));
            if (vt != s.begin() && it2 != s.end()) k.insert(*it2 - *it1);
            s.erase(vt);
        }
        else {
            auto it1 = s.upper(p);
            auto it2 = it1;
            if (it1 != s.end()) k.insert(*it1 - p);
            if (it1 != s.begin()){
                --it2;
                if (it1 != s.end()) k.erase(k.find(*it1 - *it2));
                k.insert(p - *it2);
            }
            s.insert(p);
        }
        cout << (k.empty() ? - 1 : *k.begin()) << endl;
    }
}