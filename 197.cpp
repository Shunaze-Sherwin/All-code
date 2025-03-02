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

const int mx = 1e5;
const int mod = 1e9 + 7;

int n;
vector<int> v;

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "BAI5"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    fu(i, 1, n){
        int x;
        cin >> x;
        v.pb(x);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    int ma = 0;
    fu(i, 0, v.size() - 1){
        int vt = lower(all(v), v[i] + n - 1) - v.begin();
        if (vt == v.size() || v[vt] > v[i] + n - 1) --vt;
        ma = max(ma, vt - i + 1);
    }
    cout << n - ma;
}