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
int n, m;
int A[mx + 5][mx + 5];
bool vi[mx + 5][mx + 5] = { };
int cost[mx + 5][mx + 5] = { };

void bfs(){
    queue<pa> qu;
    qu.push({1, 1});
    while (!qu.empty()){
        int a = (qu.front()).fi, b = (qu.front()).se;
        qu.pop();
        vi[a][b] = true;
        fu(i, 0, 3){
            int x = a + X[i];
            int y = b + Y[i];
            if (x > 0 && y > 0 && x <= n && y <= m && !vi[x][y] && A[x][y] == 0) 
                qu.push({x, y}), cost[x][y] = cost[a][b] + 1;
        }
    }
    cout << (cost[n][m] == 0 ? -1 : cost[n][m]);
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
        fu(j, 1, m){
            char c;
            cin >> c;
            A[i][j] = c -'0';
        }
    bfs();
}