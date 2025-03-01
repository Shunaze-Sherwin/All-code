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
#define int ll

const int mod = 1e9;
const int mx = 2e7;

ll n, s;
pa A[mx + 5];
ll L[mx + 5];
vector<pa> v1, v2;

bool com(pa a, pa b){
    if (a.fi != b.fi) return a.fi < b.fi;
    return a.se < b.se;
}

void try1(int vt, ll t, ll val){
    if (t > s) return ;
    if (vt > n/2){
        v1.pb({t, val});
        return ;
    }
    try1(vt + 1, t + A[vt].fi, val + A[vt].se);
    try1(vt + 1, t, val);
}

void try2(int vt, ll t, ll val){
    if (t > s) return ;
    if (vt > n) {
        v2.pb({t, val});
        return ;
    }
    try2(vt + 1, t + A[vt].fi, val + A[vt].se);
    try2(vt + 1, t, val);
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

    cin >> n >> s;
    fu(i, 1, n) cin >> A[i].fi >> A[i].se;
    try1(1, 0, 0);
    try2(n/2 + 1, 0, 0);
    sort(all(v1), com);
    sort(all(v2), com);
    L[0] = v2[0].second;
    for (int i = 1; i < v2.size(); ++i) L[i] = max(L[i - 1], v2[i].second);
    ll ans = 0;
    for (pa i : v1){
        int vt = upper(all(v2), mp(s - i.fi, s), com) - v2.begin();
        if (vt <= 0) continue;
        --vt;
        ans = max(ans, i.se + L[vt]);
    }
    cout << ans;
}