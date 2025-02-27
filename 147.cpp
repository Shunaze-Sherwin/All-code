#include <bits/stdc++.h>

using namespace std;

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
#define up upper_bound
#define low lower_bound
#define bin binary_search
#define all(a) (a).begin(), (a).end()
#define bit(i, mask) ((mask) & (1 << (i)))
#define reset(a) memset(all(a), 0, sizeof(a))
#define fu(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define fd(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define fill(A, l, r, val) fill(A + l, A + r + 1, val)
#define int ll

const int MOD = 1e9 + 7;
const int mx = 5e3;
const ll inf = 1e18 + 15;

int A[2][mx + 5] = { }, B[2][mx + 5] = { };

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "swap"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    fu(i, 1, n){
        int x;
        cin >> x;
        A[0][0] = B[0][0] + x;
        A[1][0] = B[1][0];
        fu(j, 1, k){
            A[0][j] = max(B[0][j], B[1][j]) + x;
            A[1][j] = max(B[1][j], B[0][j - 1]);
        }
        fu(j, 0, 1)
            fu(u, 0, k) B[j][u] = A[j][u];
    }
    int ans = -inf;
    cout << max(A[0][k], A[1][k]) << endl;
}