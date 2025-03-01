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
const int mx = 1e5;

int A[mx + 5];

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

    int n, k;
    cin >> n >> k;
    fu(i, 1, n) cin >> A[i];
    sort(A + 1, A + n + 1);
    int l = 1, r = 1e9;
    while (r >= l){
        int mid = (l + r) >> 1;
        int de = 1, vt = 1;
        while (vt <= n){
            auto tmp = lower(A + vt, A + n + 1, A[vt] + mid);
            if (tmp != A + n + 1) ++de;
            vt = tmp - A;
        }
        if (de >= k) l = mid + 1;
        else r = mid - 1;
    }
    cout << r;
}