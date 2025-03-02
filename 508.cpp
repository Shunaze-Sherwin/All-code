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
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)
#define all(a) a.begin(), a.end()
#define int ll

const int mod  = 1e9 + 7;
const int mx = 1e5;

int A[mx + 5];
ll T[mx + 5];
ll R[mx + 5];

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
    T[0] = 0;
    fu(i, 1, n) T[i] = T[i - 1] + A[i];
    ll ma = -inf;
    R[n + 1] = -inf;
    fd(i, n, 1){
        ma = max(ma, T[i]);
        R[i] = max(R[i + 1], ma - T[i - 1]);
    }
    ll mi = 0;
    ll val = -inf;
    ma = -inf;
    fu(i, 1, n){
        val = max(val, T[i] - mi);
        mi = min(mi, T[i]);
        ma = max(ma, val + R[i + 1]);
    }
    cout << ma;
}