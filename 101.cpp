#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ld long double
#define ull unsigned ll
#define pa pair<int,int>
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
#define fu(i,a,b) for (int i = a; i <= b; ++i)
#define fd(i,a,b) for (int i = a; i >= b; --i)
#define int ll

const int mod = 1e9 + 7;
const int mx = 5e2;

int A[mx + 5][mx + 5];
int T[mx + 5][mx + 5];

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "file"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".out", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    fu(i, 1, n)
        fu(j, 1, m) {
            char c;
            cin >> c;
            A[i][j] = c - '0';
            A[i][j] += A[i][j - 1];
        }
    fu(i, 1, m)
        fu(j, 1, n) T[j][i] = T[j - 1][i] + A[j][i];
    ll ans = 0;
    fu(i, 1, n)
        fu(j, 1, m){
            int v = 1;
            fd(u, i, 1){
                while (v < j && T[i][j] - T[i][v - 1] - T[u - 1][j] + T[u - 1][v - 1] > k) ++v;
                if (T[i][j] - T[i][v - 1] - T[u - 1][j] + T[u - 1][v - 1] <= k) 
                    ans = max((j - v + 1)*(i - u + 1), ans);
                else break;
            }
        }
    cout << ans;
}