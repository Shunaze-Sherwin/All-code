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

const int mod = 1e9;
const int mx = 1e5;

vector<int> v[mx + 5];
bool vi[mx + 5] = { };
int cost[mx + 5] = { };

void bfs(int vt){
    queue<int> qu;
    qu.push(vt);
    vi[vt] = true;
    while (!qu.empty()){
        int tmp = qu.front();
        for (int i : v[tmp])
            if (!vi[i]){
                vi[i] = true;
                cost[i] = cost[tmp] + 1;
                qu.push(i);
            }
        qu.pop();
    }
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

    int n, m;
    cin >> n >> m;
    fu(i, 1, m){
        int l, r;
        cin >> l >> r;
        v[l].pb(r);
        v[r].pb(l);
    }
    bfs(1);
    ll ans = cost[n], vt = n;
    cout << cost[n] << endl;
    vector<int> res;
    res.pb(n);
    while (ans){
        for (int i : v[vt])
            if (cost[i] == ans - 1){
                res.pb(i);
                --ans;
                vt = i;
                break;
            }
    }
    reverse(all(res));
    for (int i : res) cout << i << char(32);
}