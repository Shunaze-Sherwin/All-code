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
const int mx = 2e6;
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
    if (k > n) return 0;
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

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    pre();
    int s, n, l, h;
    cin >> s >> n >> l >> h;
    s -= l*n;
    h -= l;
    int ans = C(n - 1, s + n - 1);
    fu(i, 1, n){
        int val = C(i, n);
        if (i & 1) ans = (ans - val*C(n - 1, s - i*(h + 1) + n - 1)%MOD + MOD)%MOD;
        else ans = (ans + val*C(n - 1, s - i*(h + 1) + n - 1)%MOD)%MOD;
    }
    cout << ans;
}