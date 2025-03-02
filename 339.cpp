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

bool SG[mx + 5];

void sang(){
    memset(SG, true, sizeof(SG));
    SG[0] = SG[1] = false;
    for (int i = 2; i*i <= mx; ++i)
        if (SG[i]){
            int j = i*i;
            while (j <= mx){
                SG[j] = false;
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
    vector<int> v;
    fu(i, 1, sqrt(1e9))
        if (SG[i]) v.pb(i);
    int q;
    cin >> q;
    while (q--){
        int n;
        cin >> n;
        ll ans = 1;
        for (int i : v){
            int de = 0;
            while (n%i == 0) ++de, n /= i;
            ans *= (de + 1);
        }
        if (n > 1) ans <<= 1;
        cout << ans << endl;
    }
}