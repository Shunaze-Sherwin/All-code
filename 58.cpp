#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ull unsigned ll
#define pa pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define log __lg
#define all(a) a.begin(), a.end()
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)

const int mod = 1e9 + 7;
const int mx = 1e3;

int n;
int A[15][15] = { };
int vi[15] = { };
int cost[15];
int mi;
int d;

void dequy(int vt, int de, int t){
    if (de == n){
        fu(i, 1, 15) cost[i] = INT_MAX;
        set<pa> s;
        s.insert({0, vt});
        cost[vt] = 0;
        while (!s.empty()){
            pa temp = *s.begin();
            s.erase(s.begin());
            if (temp.fi > cost[temp.se]) continue;
            fu(i, 1, n)
                if (A[temp.se][i] + temp.fi < cost[i]){
                    cost[i] = A[temp.se][i] + temp.fi;
                    s.insert({cost[i], i});
                }
        }
        mi = min(mi, t + cost[d]);
    }
    fu(i, 1, n)
        if (vi[i] != vi[vt]){
            vi[i] = vi[vt];
            dequy(i, de + 1, t + A[vt][i]);
            vi[i] = 0;
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

    cin >> n;
    fu(i, 1, n)
        fu(j, 1, n) cin >> A[i][j];
    mi = INT_MAX;
    vi[1] = 1;
    d = 1;
    dequy(1, 1, 0);
    cout << mi;
}