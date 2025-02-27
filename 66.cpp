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
#define endl '\n'
#define lower lower_bound
#define upper upper_bound
#define search binary_search
#define all(a) a.begin(), a.end()
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)

const int mx = 1e3;
const int mod = 1e9 + 7;

ll A[mx + 5][mx + 5] = { };

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

	int n, m, q;
    cin >> n >> m >> q;
    fu(i, 1, n)
        fu(j, 1, m) {
            cin >> A[i][j];
            A[i][j] += A[i][j - 1];
        }
    fu(i, 1, m)
        fu(j, 1, n) A[j][i] += A[j - 1][i];
    while (q--){
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        cout << A[l][r] - A[l][y - 1] - A[x - 1][r] + A[x - 1][y - 1] << endl;
    }
}