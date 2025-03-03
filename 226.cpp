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

const int MOD = 1e9 + 7;
const int mx = 1e5;
const int inf = 1e18 + 15;

int fact[mx + 5];
int invm[mx + 5];
int invf[mx + 5];

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
    return fact[n]*invf[k]%MOD*invf[n - k]%MOD;
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
    int n, k;
    cin >> n >> k;
    int ans = fact[n];
    fu(i, 1, k){
        int val = C(i, k);
        if (i & 1) ans = (ans - val*fact[n - i]%MOD + MOD)%MOD;
        else ans = (ans + val*fact[n - i]%MOD)%MOD;
    }
    cout << ans;
}