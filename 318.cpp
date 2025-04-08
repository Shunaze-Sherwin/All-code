#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
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
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define all(a) a.begin(), a.end()
#define fu(i, a, b) for (int i = (int)a; i <= (int)b; ++i)
#define fd(i, a, b) for (int i = (int)a; i >= (int)b; --i)

const int mod = 1e9 + 7;
const int mx = 1e5;

int par[2*mx + 5];

int find(int u){
    if (u == par[u]) return u;
    return par[u] = find(par[u]);
}

void join(int u, int v){
    int a = find(u), b = find(v);
    if (a > b) swap(a, b);
    if (a != b) par[b] = a;
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

	int n, q;
    cin >> n >> q;
    fu(i, 1, 2*n) par[i] = i;
    while (q--){
        int c, u, v;
        cin >> c >> u >> v;
        if (c == 1){
            join(u, v + n);
            join(v, u + n);
        }
        if (c == 2){
            int a = find(u), b = find(v);
            if (a == b) {
                cout << "SAFE" << endl;
                continue;
            }
            a = find(u + n);
            if (a == b){
                cout << "FATAL" << endl;
                continue;
            }
            cout << "DUNNO" << endl;
        }
    }
}


/*
    -AC
 -> -TLE ?

*/