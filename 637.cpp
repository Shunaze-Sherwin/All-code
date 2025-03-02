#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ull unsigned ll
#define pa pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define log __lg
#define gcd __gcd
#define endl '\n'
#define lower lower_bound
#define upper upper_bound
#define search binary_search
#define all(a) a.begin(), a.end()
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)
#define int ll

const int mx = 2e5;
const int mod = 1e9 + 7;

ll A[mx + 5];
ll T[mx + 5];

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "BAI5"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, s;
    cin >> n >> s;
    T[0] = 0;
    fu(i, 1, n) {
        cin >> A[i];
        T[i] = T[i - 1] + A[i];
    }
    ll ma = 0;
    fu(i, 1, n){
        int vt = lower(T, T + i, T[i] - s) - T;
        ma = max(ma, i - vt);
        T[i] = max(T[i - 1], T[i]);
    }
    cout << ma;
}