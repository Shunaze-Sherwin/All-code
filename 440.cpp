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

int A[mx + 5], B[mx + 5];
double C[mx + 5];
int n, k;

bool check(ld val){
    fu(i, 1, n) C[i] = (double)A[i] - (double)val*B[i];
    sort(C + 1, C + n + 1, greater<double>());
    ld t = 0;
    fu(i, 1, k) t += C[i];
    return t >= 0;
}

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "SEED"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".out", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    fu(i, 1, n) cin >> A[i] >> B[i];
    double l = 0, r = 1e9;
    while (r - l >= 1e-6){
        double mid = (l + r)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << setprecision(3) << fixed << l;
}