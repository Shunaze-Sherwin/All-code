#include <bits/stdc++.h>
#include <queue>

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

int n, m;
bool vi[mx + 5] = { };
vector<int> v[mx + 5];
int cost[mx + 5] = { };

bool bfs(int vt){
    queue<int> qu;
    qu.push(vt);
    cost[vt] = 0;
    while (!qu.empty()){
        int val = qu.front();
        qu.pop();
        for (int i : v[val])
            if (cost[i] != cost[val])
                if (cost[i] == inf){
                    cost[i] = (cost[val] + 1)%2;
                    qu.push(i);
                }
                else ;
            else return false;
    }
    return true;
}

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "SCHEDULE"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    fu(i, 1, m){
        int l, r;
        cin >> l >> r;
        v[r].pb(l);
        v[l].pb(r);
    }
    fu(i, 1, n) cost[i] = inf;
    bool kt = true;
    fu(i, 1, n)
        if (cost[i] == inf) kt = min(kt, bfs(i));
    cout << (kt ? "YES" : "NO");
}