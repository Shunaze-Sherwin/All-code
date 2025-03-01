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

int f[mx + 5] = { };

void sang(){
    fu(i, 1, mx) f[i] = 2;
    f[1] = 1;
    for (int i = 2; i*i <= mx; ++i){
        int j = i*i;
        while (j <= mx){
            if (j != i*i) f[j] += 2;
            else ++f[j];
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
    fu(i, 1, mx) f[i] += f[i - 1];
    int q;
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << f[r] - f[l - 1] << endl;
    }
}