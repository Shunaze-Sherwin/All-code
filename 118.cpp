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
const int mx = 2e5;

int n, m;
bool vi[mx + 5] = { };

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
    queue<pa> qu;
    qu.push({n, 0});
    while (!qu.empty()){
        pa val = qu.front();
        qu.pop();
        vi[val.fi] = true;
        if (val.fi == m){
            cout << val.se;
            return 0;
        }
        if (val.fi > 1){
            if (val.fi <= m && !vi[val.fi*2]) qu.push({val.fi*2, val.se + 1});
            if (!vi[val.fi - 1]) qu.push({val.fi - 1, val.se + 1});
        }
    }
}