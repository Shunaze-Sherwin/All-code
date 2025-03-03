#include <bits/stdc++.h>

using namespace std;

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
#define up upper_bound
#define low lower_bound
#define all(a) (a).begin(), (a).end()
#define bit(i, mask) (mask & (1 << i))
#define reset(A, val) memset(A, val, sizeof(A))
#define fu(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define int ll

const int inf = 1e18 + 15;
const int MOD = 1e9 + 7;
const int mx = 1e6 + 15;

int f[mx + 5];
vector<pa> v;

int fact[mx + 5];
int invm[mx + 5];
int invf[mx + 5];

void pre(){
    fact[0] = fact[1] = 1;
    invm[0] = invm[1] = 1;
    invf[0] = invf[1] = 1;
    fu(i, 2, mx){
        fact[i] = fact[i - 1]*i%MOD;
        invm[i] = MOD - (MOD/i)*invm[MOD%i]%MOD;
        invf[i] = invf[i - 1]*invm[i]%MOD;
    }
}

int C(int k, int n){
    if (n < k) return 0;
    return fact[n]*invf[k]%MOD*invf[n - k]%MOD;
}

int calc(int a, int b, int x, int y){
    if (a > x || b > y) return 0;
    return C(x - a, x + y - a - b);
}

signed main(){
    
    #define name "Sherwin"
    if (fopen(name".INP","r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "file"
    if (fopen(name".INP","r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    pre();
    int n, m, k;
    cin >> n >> m >> k;
    fu(i, 1, k){
        int a, b;
        cin >> a >> b;
        v.pb({a, b});
    }
    sort(all(v));
    fu(i, 0, (int)v.size() - 1){
        f[i] = calc(1, 1, v[i].fi, v[i].se);
        fu(j, 0, i - 1)
            if (v[i].fi >= v[j].fi && v[i].se >= v[j].se) 
                f[i] = (f[i] - f[j]*calc(v[j].fi, v[j].se, v[i].fi, v[i].se)%MOD + MOD)%MOD;
    }
    int ans = calc(1, 1, n, m);
    fu(i, 0, v.size() - 1)
        ans = (ans - f[i]*calc(v[i].fi, v[i].se, n, m)%MOD + MOD)%MOD;
    cout << ans;
}