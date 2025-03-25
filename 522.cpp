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
#define log __lg
#define endl '\n'
#define upper upper_bound
#define lower lower_bound
#define all(a) (a).begin(), (a).end()
#define bit(i, mask) (mask & (1ll << (i)))
#define reset(a, val) memset(a, val, sizeof(a))
#define fu(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define int ll

constexpr int MOD = 1e5 + 3;
constexpr int mx = 1e5;
constexpr int maxn = 1e6;
constexpr int LOG = log(mx);
constexpr ll inf = 1e18 + 15;

void add(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
void sub(int &a, int b){a -= b; if (a < 0) a += MOD;}
void mul(int &a, int b){a = 1ll * (a%MOD) * (b%MOD) % MOD;}

int A[mx + 5];

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "maze"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    fu(i, 1, n) {
        cin >> A[i];
        A[i] ^= i;
    }
    sort(A + 1, A + n + 1);
    A[n + 1] = -1;
    int cnt = 1;
    int ans = 0;
    fu(i, 1, n)
        if (A[i] == A[i + 1]) ++cnt;
        else{
            ans += (cnt - 1)*cnt/2;
            cnt = 1;
        }
    cout << ans;
}
/*

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/