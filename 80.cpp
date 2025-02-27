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

const int mx = 1e5;
const int mod = 1e9 + 7;
const int sm = 1e6;

int A[mx + 5];

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "W", stdout);
    }

    #define name "DINER"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "W", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, l, r;
    cin >> n >> l >> r;
    fu(i, 1, n) cin >> A[i];
    ll de = 0;
    sort(A + 1, A + n + 1);
    fu(i, 1, n){
        int vtc = upper(A + 1, A + i, r - A[i]) - A;
        int vtd = lower(A + 1, A + i, l - A[i]) - A;
        de += vtc - vtd;
    }
    cout << de;
}