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
const int mx = 1e5;

pa A[mx + 5];

signed main(){

    #define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    #define name "file"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".out", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    cin >> n >> x;
    fu(i, 1, n) {
        cin >> A[i].fi;
        A[i].se = i;
    }
    sort(A + 1, A + n + 1);
    fu(i, 1, n){
        int k = n;
        fu(j, 1, i){
            while (k > 1 && A[i].fi + A[j].fi + A[k].fi > x) --k;
            if (A[i].fi + A[j].fi + A[k].fi == x){
                cout << A[i].se << char(32) << A[j].se << char(32) << A[k].se;
                return 0;
            } 
        }
    }
}