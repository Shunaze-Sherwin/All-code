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
#define endl '\n'
#define gcd __gcd
#define log __lg
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define all(a) a.begin(), a.end()
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)

const int mod = 1e9 + 7;
const int mx = 1e6;

ll M[mx + 5], T[mx + 5], B[mx + 5];

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
    T[0] = 1;
    B[0] = 0;
    fu(i, 1, 18) T[i] = T[i - 1]*10, M[i] = 9*T[i - 1]*i;
    fu(i, 1, 18) B[i] = B[i - 1] + M[i];
    ll k;
    cin >> k;
    int vt = lower_bound(B + 1, B + 19, k) - B;
    k-= B[vt - 1] + 1;
    ll val = k/vt + T[vt - 1];
    int calc = k%vt;
    string s = to_string(val);
    cout << s[calc];
}