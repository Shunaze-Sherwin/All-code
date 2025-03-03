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
const int mx = 1e3 + 15;
const int maxn = (1 << 15);
bool vi[mx + 5] = { };
int D[maxn + 5] = { };


vector<int> solve(char A[]){
    reset(vi, false);
    vector<int> res;
    fu(i, 0, 9)
        if (A[i] != NULL && !vi[A[i]]){
            vi[A[i]] = true;
            res.pb(A[i] - 'a');
        }
    return res;
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

    int n;
    cin >> n;
    int ans = 0;
    fu(i, 1, n) {
        char A[15] = { };
        cin >> A;
        vector<int> v = solve(A);
        int last = (1 << (int)v.size()) - 1;
        int cnt = 0;
        fu(mask, 1, last){
            int t = 0;
            fu(j, 0, v.size() - 1)
                if (bit(j, mask)) t = t | (1 << v[j]);
            int k = __builtin_popcount(mask);
            if (k & 1) cnt += D[t];
            else cnt -= D[t];
        }
        ans += cnt;
        fu(mask, 1, last){
            int t = 0;
            fu(j, 0, v.size() - 1)
                if (bit(j, mask)) t = t | (1 << v[j]);
            ++D[t];
        }
    }
    cout << ans;
}