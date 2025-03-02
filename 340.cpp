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

int D[mx + 5] = { };

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

    int n;
    cin >> n;
    fu(i, 1, n){
        int x;
        cin >> x;
        ++D[x];
    }
    fd(i, mx, 1){
        int j = 2*i;
        while (j <= mx){
            D[i] += D[j];
            j += i;
        }
        if (D[i] > 1){
            cout << i;
            return 0;
        }
    }
}