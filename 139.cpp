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
    if (a < b) swap(a, b);
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
    fu(i, 1, 2*n + 1) par[i] = i;
    fu(i, 1, q){ 
        int u, v, t;
        cin >> u >> v >> t;
        ++v;
        if (t == 0) join(u, v), join(u + n + 1, v + n + 1);
        if (t == 1) join(v, u + n + 1), join(u, v + n + 1);
        if (find(u) == find(u + n + 1) || find(v) == find(v + n + 1)){
            cout << i - 1;
            return 0;
        }
    }
    cout << q;
}


/*
    -AC
 -> -TLE ?

*/