#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ld long double
#define ull unsigned ll
#define pa pair<int,int>
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

const int mod = 1e9 + 7;
const int mx = 2e5;

ll n, t = 0;
ll A[mx + 5];
vector<ll> v1, v2;

void try1(int vt, ll t){
    if (vt > n/2){
        v1.pb(t);
        return ;
    }
    try1(vt + 1, t + A[vt]);
    try1(vt + 1, t);
}

void try2(int vt, ll t){
    if (vt > n) {
        v2.pb(t);
        return ;
    }
    try2(vt + 1, t + A[vt]);
    try2(vt + 1, t);
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
    fu(i, 1, n) cin >> A[i], t += A[i];
    try1(1, 0);
    try2(n/2 + 1, 0);
    v1.erase(v1.begin() + v1.size() - 1);
    v2.erase(v2.begin() + v2.size() - 1);
    sort(all(v1));
    sort(all(v2));
    ll ans = inf;
    for (ll i : v1){
        auto vt = lower(all(v2), (t - 2*i)/2);
        ans = min(ans, abs(t - 2*(i + *vt)));
        if (vt != v2.begin()) --vt;
        ans = min(ans, abs(t - 2*(i + *vt)));
    }
    cout << ans;
}