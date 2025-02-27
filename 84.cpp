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
#define int ll

const int mod = 1e9 + 7;
const int mx = 5e5;

ll check(ll val){   
    ll ans = 0;
    vector<int> v = {3, 5, 7};
    fu(i, 1, (1 << 3)-1){
        int de = 0, t = 1;
        fu(j, 0, 2)
            if (i & (1 << j)){
                ++de;
                t *= v[j];
            }
        if (de & 1) ans += val/t;
        else ans -= val/t;
    }
    return ans;
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

    int k;
    cin >> k;
    ll l = 3, r = inf;
    while (r >= l){
        ll mid = (l + r) >> 1;
        if (check(mid) >= k) r = mid - 1;
        else l = mid + 1;
    }
    cout << l;
}