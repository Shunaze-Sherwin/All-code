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
#define fu(i,a,b) for (int i = (int)a; i <= (int)b; ++i)
#define fd(i,a,b) for (int i = (int)a; i >= (int)b; --i)

const int mod = 1e9 + 7;
const int mx = 2e5;

ll n, x;
ll A[mx + 5];
unordered_map<ll, bool> D;

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

    cin >> n >> x;
    fu(i, 1, n) cin >> A[i];
    fu(i, 1, n){
        fu(j, i + 1, n)
            if (D.find(x - A[i] - A[j]) != D.end()){
                cout << "YES";
                return 0;
            }
        fu(j, 1, i - 1) D[A[i] + A[j]] = true;
    }
    cout << "NO";
}