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
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)

const int mod = 1e9 + 7;
const int mx = 1e5;

struct gt{
    int u, v, w, index;
};

gt A[mx + 5];
int ans[mx + 5] = { };
int par[mx + 5];

bool com(gt a, gt b){
    return a.w < b.w;   
}

int find(int u){
    if (u == par[u]) return u;
    return par[u] = find(par[u]);
}

void join(int u, int v){
    int a = find(u), b = find(v);
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

	int n, m;
    cin >> n >> m;
    fu(i, 1, m) cin >> A[i].u >> A[i].v >> A[i].w;
    fu(i, 1, m) A[i].index = i;
    fu(i, 1, n) par[i] = i;  
    sort(A + 1, A + m + 1, com);
    int x = 0;
    fu(i, 1, m){
        if (A[i].w != x){
            fd(j, i - 1, 1){
                if (A[j].w != x) break;
                join(A[j].u, A[j].v);
            }
            x = A[i].w;
        }
        if (find(A[i].u) != find(A[i].v)) ans[A[i].index] = 1;
        else ans[A[i].index] = 0;
    }
    fu(i, 1, m) cout << ans[i];
}