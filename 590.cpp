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
#define fu(i,a,b) for (int i = (int)a; i <= (int)b; ++i)
#define fd(i,a,b) for (int i = (int)a; i >= (int)b; --i)
#define int ll

const int mod = 1e9 + 7;
const int mx = 1e6;

ll L[mx + 5], R[mx + 5], A[mx + 5];

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

    int n;
    cin >> n;
    fu(i, 1, n) cin >> A[i];
    L[1] = A[1];
    fu(i, 2, n) L[i] = gcd(A[i], L[i - 1]);
    R[n] = A[n];
    fd(i, n - 1, 1) R[i] = gcd(R[i + 1], A[i]);
    ll ans = max(R[2], L[n - 1]);
    fu(i, 2, n - 1) ans = max(ans, gcd(L[i - 1], R[i + 1]));
    cout << ans;
}