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
const int mx = 20;
const int inf = 1e18 + 15;

int fact[mx + 5];
int invm[mx + 5];
int invf[mx + 5];
int A[mx + 5];

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
    int res = 1;
    fu(i, n - k + 1, n) res = res*i%MOD;
    return res*invf[k]%MOD;
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
    int n, s;
    cin >> n >> s;
    fu(i, 1, n) cin >> A[i];
    int ans = C(n - 1, n + s - 1);
    int last = (1 << n) - 1;
    fu(mask, 1, last){
        int t = 0;
        fu(i, 1, n)
            if (bit(i - 1, mask)) t += A[i] + 1;
        int k = __builtin_popcount(mask);
        if (k & 1) ans = (ans - C(n - 1, s - t + n - 1) + MOD)%MOD;
        else ans = (ans + C(n - 1, s - t  + n - 1))%MOD;
    }
    cout << ans;
}