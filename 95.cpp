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

int A[mx + 5];
int L[mx + 5], R[mx + 5];

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

    int n, k;
    cin >> n >> k;
    fu(i, 1, n) cin >> A[i];
    sort(A + 1, A + n + 1);
    int ma = 0;
    int j = 1;
    L[0] = 0;
    fu(i, 1, n){
        while (A[i] - A[j] > k) ++j;
        L[i] = max(L[i - 1], i - j + 1);
    }
    R[n + 1] = 0;
    j = n;
    fd(i, n, 1){
        while (A[j] - A[i] > k) --j;
        R[i] = max(R[i + 1], j - i + 1);
    }
    fu(i, 1, n) ma = max(ma, L[i] + R[i + 1]);
    cout << ma;
}