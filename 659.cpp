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
#define int ll

const int mod = 1e9;
const int mx = 2e5;

pa A[mx + 5];
priority_queue<int> qu;
int vt = 0, t = 0, n, m;

bool com(pa a, pa b){
    if (a.fi != b.fi) return a.fi < b.fi;
    return a.se < b.se;
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

    cin >> n >> m;
    fu(i, 1, n) cin >> A[i].fi >> A[i].se;
    sort(A + 1, A + n + 1, com);
    ll ans = 0;
    fu(i, 1, n){
        qu.push(A[i].se);
        t += A[i].se;
        while (!qu.empty() &&t + A[i].fi > m){
            t -= qu.top();
            qu.pop();
        }
        ans = max(ans, (ll)qu.size());
    }
    cout << ans;
}