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
#define all(a) a.begin(), a.end();

const int mod  = 1e9 + 7;
const int mx = 1e5;

int A[mx + 5];
ll T[mx + 5];

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
    fu(i, 1, n){
        ll val1 = T[i];
        ll val2 = T[n] - T[i];
        ma = max(ma, val1*(-1) + val2);
        ma = max(ma, val1 + val2*(-1));
    }
    cout << ma;
}