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

const int mod = 1e9 + 7;
const int mx = 1e5;

ll cost[mx + 5];
ll L[mx + 5];
vector<int> v[mx + 5];

void di(int a){
    priority_queue<pa, vector<pa>, greater<pa>> qu;
    cost[a] = 0;
    qu.push({0, a});
    while (!qu.empty()){
        pa temp = qu.top();
        qu.pop();
        if (cost[temp.se] < temp.fi) continue;
        for (int i : v[temp.se])
            if (cost[i] > temp.fi + 1){
                cost[i] = temp.fi + 1;
                qu.push({cost[i], i});
            }
    }
}

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "MULTIDSEQ"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int a, b;
    cin >> a >> b;
    fu(i, 1, m){
        int l, r;
        cin >> l >> r;
        v[l].pb(r);
        v[r].pb(l);
    }
    fu(i, 1, n) cost[i] = inf;
    di(a);
    fu(i, 1, n) L[i] = cost[i], cost[i] = inf;
    di(b);
    ll de = 0;
    fu(i, 1, n)
        if (L[i] <= cost[i] && L[i] != inf) ++de;
    cout << de;
}