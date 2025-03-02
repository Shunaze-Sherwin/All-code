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

struct gt{
    int val, de, index;
};

#define struct gt gt

bool com(gt a, gt b){
    if (a.val != b.val) return a.val < b.val;
    return a.de < b.de;
}

vector<gt> v;

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

    int n, q;
    map<int, int> D;
    cin >> n >> q;
    fu(i, 1, n){
        int x;
        cin >> x;
        ++D[x];
        v.pb({x, D[x], i});
    }
    sort(all(v), com);
    while (q--){
        int x, k;
        cin >> x >> k;
        gt temp = {x, k, 0};
        gt vt = *lower(all(v), temp, com);
        cout << vt.index << endl;
    }
}