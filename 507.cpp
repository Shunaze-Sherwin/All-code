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
#define fu(i,a,b) for (int i = a; i <= b; ++i)
#define fd(i,a,b) for (int i = a; i >= b; --i)
#define int ll

const int mod = 1e9 + 7;
const int mx = 1e5;

int A[mx + 5], B[mx + 5], C[mx + 5];

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "file"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".out", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;   
    fu(i, 1, n) cin >> A[i];
    fu(i, 1, n) cin >> B[i];
    fu(i, 1, n) cin >> C[i];
    sort(A + 1, A + n + 1);
    sort(B + 1, B + n + 1);
    sort(C + 1, C + n + 1);
    ll ans = inf;
    int j = 1, k = 1;
    fu(i, 1, n){
        while (j < n && abs(A[i] - B[j]) >= abs(A[i] - B[j + 1])) ++j;
        while (k < n && abs(A[i] - C[k]) >= abs(A[i] - C[k + 1])) ++k;
        ans = min(ans, abs(A[i] - B[j]) + abs(A[i] - C[k]) + abs(B[j] - C[k]));
    }
    cout << ans;
}
