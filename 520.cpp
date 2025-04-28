#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned ll
#define pa pair<ll, ll>
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
#define all(a) (a).begin(), (a).end()
#define fu(i,a,b) for (int i = (int)a; i <= (int)b; ++i)
#define fd(i,a,b) for (int i = (int)a; i >= (int)b; --i)

const int mod = 100;
const int mx = 1e5;
const ll inf = 1e18;

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

    int q;
    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        int ans = 0;
        fu(i, 0, 4){
            int x = a & (1 << i);
            int y = b & (1 << i);
            if (x ^ y & (1 << i)) ans += (1 << i);
        }
        fu(i, 5, 9){
            int x = a & (1 << i);
            int y = b & (1 << i);
            if (x & y & (1 << i)) ans += (1 << i);
        }
        fu(i, 10, 14){
            int x = a & (1 << i);
            int y = b & (1 << i);
            if (x | y & (1 << i)) ans += (1 << i);
        }
        cout << ans << endl;
    }
}