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
vector<pa> s1, s2;

bool com(pa a, pa b){
    if (a.fi != b.fi) return a.fi < b.fi;
    return a.se < b.se;
}

void try1(int vt, ll t1, ll t2){
    if (vt > n/2){
        s1.pb({t1, t2});
        return ;
    }
    try1(vt + 1, t1 + A[vt].fi, t2 + A[vt].se);
    try1(vt + 1, t1, t2);
}

void try2(int vt, ll t1, ll t2){
    if (vt > n) {
        s2.pb({t1, t2});
        return ;
    }
    try2(vt + 1, t1 + A[vt].fi, t2 + A[vt].se);
    try2(vt + 1, t1, t2);
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

    cin >> n;
    ll a, b;
    cin >> a >> b;
    fu(i, 1, n) cin >> A[i].fi >> A[i].se;
    try1(1, 0, 0);
    try2(n/2 + 1, 0, 0);
    sort(all(s1), com);
    sort(all(s2), com);
    ll ans = 0;
    for (pa i : s1){
        int vtc = upper(all(s2), mp(a - i.fi, b - i.se), com) - s2.begin();
        int vtd = lower(all(s2), mp(a - i.fi, b - i.se), com) - s2.begin();
        ans += vtc - vtd;
    }
    cout << ans;
}