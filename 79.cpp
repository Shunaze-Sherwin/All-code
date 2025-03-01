#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ull unsigned ll
#define pa pair<int, int>
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
#define int ll

const int mx = 1e6;
const int mod = 1e9 + 7;

pa A[mx + 5];

bool com(pa a, pa b){
    if (a.fi != b.fi) return a.fi < b.fi;
    return a.se < b.se;
}

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "W", stdout);
    }

    #define name "file"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "W", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, q;
    cin >> n >> q;
    fu(i, 1, n){
        cin >> A[i].fi;
        A[i].se = i;
    }
    sort(A + 1, A + n + 1, com);
    while (q--){
        int l, r, val;
        cin >> l >> r >> val;
        int vt1 = lower(A + 1, A + n + 1, mp(val, l), com) - A;
        int vt2 = upper(A + 1, A + n + 1, mp(val, r), com) - A;
        cout << vt2 - vt1 << endl;
    }
}