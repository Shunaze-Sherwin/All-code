#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ull unsgined ll
#define pa pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define gcd __gcd
#define log __lg
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define all(a) a.begin(), a.end()
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)

const int mod = 1e9 + 7;
const int mx = 1e5;

string b, a;
vector<pair<char, int>> A;

bool com(pair<char, int> x, pair<char, int> y){
    if (x.fi != y.fi) return x.fi < y.fi;
    else return x.se < y.se;
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

    cin >> a >> b;
    fu(i, 0, a.size() - 1) A.pb({a[i], i});
    sort(all(A), com);
    ll de = 0;
    fu(i, 0, b.size() - 1){
        int r = upper(all(A), mp(b[i], (int)a.size() - (int)b.size() + i), com) - A.begin();
        int l = lower(all(A), mp(b[i], i), com) - A.begin();
        de += r - l;
    }
    cout << de;
}