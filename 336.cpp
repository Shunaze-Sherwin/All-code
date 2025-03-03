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

constexpr int MOD = 1e9 + 7;
constexpr int mx = 1e6;
constexpr int inf = 1e18 + 15;

int fact[mx + 5];
int invm[mx + 5];
int invf[mx + 5];
int A[mx + 5];

void add(int &a, int b){a += b; if (a >= MOD) a -= MOD;};
void sub(int &a, int b){a -= b; if (a < 0) a += MOD;};
void mul(int &a, int b){a = (a%MOD) * (b%MOD) % MOD;}

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

    int n, k;
    cin >> n >> k;
    deque<int> dq;
    fu(i, 1, n) cin >> A[i];
    fu(i, 1, n){
        while (dq.size() && A[dq.back()] > A[i]) dq.pop_back();
        dq.pb(i);
        if (i >= k) {
            cout << A[dq.front()] << char(32);
            if (dq.front() == i - k + 1)dq.pop_front();
        }
    }
    
}
/*

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/