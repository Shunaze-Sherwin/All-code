#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define pa pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define up upper_bound
#define low lower_bound
#define gcd __gcd
#define log __lg
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define bit(i, mask) (mask & (1 << i))
#define reset(A, val) memset(A, val, sizeof(val))
#define fu(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); ++i)
#define fillA(A, l, r, val) fill(A + l, A + r + 1, val)
#define int ll

const int MOD = 1e9 + 7;
const int mx = 1e6;

int lcm(int a, int b){return a*b/gcd(a, b);}

int A[mx + 5];
bool vi[mx + 5];

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

    int n, q;
    cin >> n >> q;
    vector<int> v;
    for (int i = 2; i*i <= n; ++i)
        if (n%i == 0){
            v.pb(i);
            while (n%i == 0) n/= i;
        }
    if (n > 1) v.pb(n);
    int last = (1 << (int)v.size()) - 1;
    while (q--){
        int l, r;
        cin >> l >> r;
        int ans = 0;
        fu(mask, 0, last){
            int t = 1;
            fu(i, 0, (int)v.size() - 1)
                if (bit(i, mask)) t *= v[i];
            int k = __builtin_popcount(mask);
            int val = r/t - (l - 1)/t;
            if (k & 1) ans -= val;
            else ans += val;
        }
        cout << ans << endl;;
    }
}