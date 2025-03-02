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

ll A[mx + 5];

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
    
    ll n, k;
    cin >> n >> k;
    fu(i, 1, n) cin >> A[i];
    sort(A + 1, A + n + 1);
    int l = 0, r = A[n] - A[1];
    while (r >= l){
        int mid = (l + r) >> 1;
        ll de = 0;
        fu(i, 1, n){
            int it = upper_bound(A + i, A + n + 1, A[i] + mid) - A;
            de += it - i - 1;
        }
        if (de < k) l = mid + 1;
        else r = mid - 1;
    }
    cout << l;
}