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
const int mx = 1e3;

int X[] = {1, 0, 0, -1};
int Y[] = {0, 1, -1, 0};
int n, m, de = 0;
char A[mx + 5][mx + 5];
bool vi[mx + 5][mx + 5] = { };

void bfs(int x, int y){
    queue<pa> qu;
    qu.push({x, y});
    vi[x][y] = true;
    while (!qu.empty()){
        pa temp = qu.front();
        qu.pop();
        fu(i, 0, 3){
            int a = temp.fi + X[i];
            int b = temp.se + Y[i];
            if (a > 0 && b > 0 && a <= n && b <= m && A[a][b] != '#' && !vi[a][b]){
                if (A[a][b] == 'x') ++de;
                qu.push({a, b});
                vi[a][b] = true;
            }
        }
    }
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
    fu(i, 1, n)
        fu(j, 1, m) cin >> A[i][j];
    vector<int> v;
    fu(i, 1, n)
        fu(j, 1, m)
            if (A[i][j] != '#' && !vi[i][j]){
                de = (A[i][j] == 'x' ? 1 : 0);
                bfs(i, j);
                if (de > 0) v.pb(de);
            }
    sort(all(v));
    for (int i : v) cout << i << char(32);
}