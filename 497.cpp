#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ld long double
#define ull unsigned ll
#define pa pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define gcd __gcd
#define log __lg
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define all(a) a.begin(), a.end()
#define fu(i,a,b) for (int i = a; i <= b; ++i)
#define fd(i,a,b) for (int i = a; i >= b; --i)

const int mod = 1e9 + 7;
const int mx = 1e6;

int SG[mx + 5];
int A[mx + 5];
vector<pa> v;
int ans[mx + 5];

void sang(){
    fu(i, 1, mx) SG[i] = i;
    for (int i = 2; i*i <= mx; ++i)
        if (SG[i] == i){
            int j = i*i;
            while (j <= mx){
                if (SG[j] == j) SG[j] = i;
                j += i;
            }
        }
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

    sang();
    int n;
    cin >> n;
    fu(i, 1, n) ans[i] = 2*n;
    fu(i, 1, n){
        cin >> A[i];
        int x = A[i];
        int old = SG[x];
        while (x > 1){
            x /= SG[x];
            if (SG[x] != old){
                v.pb({old, i});
                old = SG[x];
            }
        }
    }
    sort(all(v));
    fu(i, 0, v.size() - 1){
        if (i > 0 && v[i].fi == v[i - 1].fi) ans[v[i].se] = min(ans[v[i].se], v[i].se - v[i - 1].se);
        if (i < v.size() - 1 && v[i].fi == v[i + 1].fi) ans[v[i].se] = min(ans[v[i].se], v[i + 1].se - v[i].se);
    }
    fu(i, 1, n){
        if (i - ans[i] > 0 && gcd(A[i], A[i - ans[i]]) > 1) cout << i - ans[i];
        else
            if (i + ans[i] <= n && gcd(A[i], A[i + ans[i]]) > 1) cout << i + ans[i];
            else cout << -1;
        cout << char(32);
    }
}