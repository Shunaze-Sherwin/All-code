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
#define int ll

const int mod = 1e9 + 7;
const int mx = 1e6;

int SG[mx + 5], D[mx + 5] = { };

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

ll power(int a, int b){
    if (b == 0) return 1;
    ll x = power(a, b/2)%mod;
    if (b & 1) return x*x%mod*a%mod;
    return x*x%mod;
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
    fu(i, 1, n){
        int x;
        cin >> x;
        int de = 0, old = SG[x];
        while (x > 1){
            ++de;
            x /= SG[x];
            if (SG[x] != old){
                D[old] = max(D[old], de);
                old = SG[x];
                de = 0;
            }
        }
    }
    ll ans = 1;
    fu(i, 2, mx) ans = ans*power(i, D[i])%mod;
    cout << ans;
}