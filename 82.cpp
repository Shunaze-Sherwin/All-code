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
#define int ll

const int mx = 1e5;
const int mod = 1e9 + 7;

vector<int> v = {2, 3, 5};
vector<ll> ans;
int n;

void dequy(ll t, int vt){
    if (t <= 1e18) ans.pb(t);
    else return ;
    fu(i, vt, 2) dequy(t*v[i], i);
}

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
    dequy(1, 0);
    sort(all(ans));
    fu(i, 1, n){
        ll val;
        cin >> val;
        int vt = lower(all(ans), val) - ans.begin();
        if (ans[vt] != val) cout << -1;
        else cout << vt + 1;
        cout << endl;
    }
}