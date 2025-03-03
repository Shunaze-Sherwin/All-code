#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define pa pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define endl '\n'
#define up upper_bound
#define low lower_bound
#define all(a) (a).begin(), (a).end()
#define bit(i, mask) (mask & (1 << i))
#define reset(a, val) memset(a, val, sizeof(val))
#define fu(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define int ll

const int MOD = 998244353;
const int mx = 1e5;
const int inf = 1e18 + 15;

int add(int a, int b){ 
    return (a + b >= MOD ? a + b - MOD : a + b);
}
int sub(int a, int b){ 
    return (a - b < 0 ? a - b + MOD : a - b);
}
ll mul(int a, int b){
    ll val = 1ll*a*b;
    return val - val/MOD*MOD;
}

int fact[mx + 5];
int invm[mx + 5];
int invf[mx + 5];
int gt[mx + 5];

void pre(){
    fact[1] = fact[0] = 1;
    invm[1] = invm[0] = 1;
    invf[1] = invf[0] = 1;
    fu(i, 2, mx){
        fact[i] = fact[i - 1]*i%MOD;
        invm[i] = MOD - MOD/i*invm[MOD%i]%MOD;
        invf[i] = invf[i - 1]*invm[i]%MOD;
    }
}   

int C(int k, int n){
    if (k > n) return 0;
    return fact[n]*invf[k]%MOD*invf[n - k]%MOD;
}

int lt(int a, int b){
    if (b == 0) return 1;
    int x = lt(a, b/2);
    if (b & 1) return x*x%MOD*a%MOD;
    return x*x%MOD;
}

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

    pre();
    int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    int ans = 0;
    gt[0] = 1;
    fu(i, 1, mx) gt[i] = gt[i - 1]*2%MOD;
    fu(i, 0, n){
        int val = C(i, n);
        if (i & 1) ans = (ans - val*lt(sub(gt[n - i], 1), m)%MOD + MOD)%MOD;
        else ans = (ans + val*lt(sub(gt[n - i], 1), m)%MOD)%MOD;
    }
    cout << ans;
}