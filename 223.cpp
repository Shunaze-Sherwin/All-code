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

    int n, l, r;
    cin >> n >> l >> r;
    fu(i, 1, n) {
        cin >> A[i];
        if (vi[A[i]]) --i, --n;
        else vi[A[i]] = true;
    }
    int last = (1 << n) - 1;
    int ans = 0;
    fu(mask, 1, last){
        int t = 1;
        bool check = false;
        fu(i, 1, n)
            if (bit(i - 1, mask)){
                if (t > r/A[i]){
                    check = true;
                    break;
                }
                t *= A[i];
            }
        if (check) continue;
        int k = __builtin_popcount(mask);
        int val = r/t - (l - 1)/t;
        if (k & 1) ans += k*val;
        else ans -= k*val;
    }
    cout << ans;
}