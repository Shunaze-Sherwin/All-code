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

int A[mx + 5];
int D[mx + 5] = { };
int K[mx + 5] = { };

int C(int k, int n){
    int res = 1;
    fu(i, n - k + 1, n) res *= i;
    return res/2;
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

    int n;
    cin >> n;
    fu(i, 1, n){
        int x;
        cin >> x;
        ++D[x];
    }
    fd(i, n, 1){
        int cnt = 0, val = 0;
        for (int j = i; j <= mx; j += i) {
            cnt += D[j];
            val = val + K[j];
        }
        int ans = C(2, cnt);
        K[i] = ans - val;
    }
    fu(i, 1, n) cout << K[i] << char(32);
}