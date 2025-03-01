#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)

const int mx = 2e5;

int A[mx + 5];
double T[mx + 5];
int n, k;

bool check(double val){
    double mi = 0;
    fu(i, 1, k - 1) T[i] = T[i - 1] + (A[i] - val);
    fu(i, k, n){
        T[i] = T[i - 1] + (A[i] - val);
        if (T[i] - mi >= 0) return true;
        mi = min(mi, T[i - k + 1]);
    }
    return false;
}

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "Average"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    fu(i, 1, n) cin >> A[i];
    T[0] = 0;
    double l = -1e9, r = 1e9;
    while (r - l > 0.0009){
        double mid = (l + r)/2;
        if (!check(mid)) r = mid;
        else l = mid;
    }
    cout << setprecision(3) << fixed << r;
}