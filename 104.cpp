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
const int mx = 1e3;
const int sm = 1e6;

int SG[sm + 5];

void sang(){
    fu(i, 1, sm) SG[i] = i;
    for (int i = 2; i*i <= sm; ++i)
        if (SG[i] == i){
            int j = i*i;
            while (j <= sm){
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
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        while (n > 1){
            int old = SG[n];
            n /= SG[n];
            if (SG[n] != old) cout << old << char(32);
        }
        cout << endl;
    }
}