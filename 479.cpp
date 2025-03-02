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
            int val;
            cin >> val;
            if (s.find(val) == s.end()) s.insert(val);
            else s.erase(val);
        }
        if (c == 2){
            int n = s.size();
            auto it = s.begin();
            if (n & 1) cout << *next(it, n/2);
            else{
                auto it1 = next(it, n/2);
                auto it2 = next(it, n/2 - 1);
                cout << (*it1 + *it2)/2;
                if ((*it1 + *it2) & 1) cout << ".5";
            }
            cout << endl;
        }
    }
}