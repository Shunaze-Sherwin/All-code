#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ull unsgined ll
#define pa pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define gcd __gcd
#define log __lg
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define all(a) a.begin(), a.end()
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)
#define int ll

const int mod = 1e9 + 7;
const int mx = 5e5;

pa A[mx + 5];
ll L[mx + 5], R[mx + 5];

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
    fu(i, 1, n) cin >> A[i].fi;
    fu(i, 1, n) cin >> A[i].se;
    sort(A + 1, A + n + 1, greater<pa>());
    R[n + 1] = -inf;
    fd(i, n, 1) R[i] = max(R[i + 1], A[i].se);
    L[0] = -inf;
    fu(i, 1, n) L[i] = max(L[i - 1], A[i].se - A[i].fi);
    ll t = 0;
    fu(i, 1, n){
        t += A[i].fi;
        cout << max(t + R[i] - A[i].fi, t + L[i]) << char(32);
    }
}