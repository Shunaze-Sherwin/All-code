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

constexpr int MOD = 998244353;
constexpr int mx = 1e5;
constexpr int inf = 1e18 + 15;

int A[mx + 5];
int B[mx + 5];
int p[mx + 5];

int lcm(int a, int b){return a*b/gcd(a, b);}
int add(int a, int b){return (a + b >= MOD ? a + b - MOD : a + b);}
int sub(int a, int b){return (a - b < 0 ? a - b + MOD : a - b);}
int mul(int a, int b){return 1ll * (a%MOD) * (b%MOD) %MOD;}

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

    int n;
    cin >> n;
    fu(i, 1, n){
        cin >> A[i] >> B[i];
        p[i] = i;
    }
    int res = inf;
    do{
        int l = 0, r = 0;
        fu(i, 1, n){
            l += A[p[i]];
            if (l > r) r = l;
            r += B[p[i]];
        }
        res = min(res, r);
    }while(next_permutation(p + 1, p + n + 1));
    cout << res;
}