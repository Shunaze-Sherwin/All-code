#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ld long double
#define ull unsigned ll
#define pa pair<int, int>
#define fi first
#define se second
#define pb pop_back
#define eb emplace_back
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

vector<int> res;
vector<int> v[mx + 5];
bool vi[mx + 5] = { };

void dfs(int vt, int val){
    vi[vt] = true;
    res.eb(val);
    for (int i : v[vt])
        if (!vi[i]) dfs(i, val + 1);
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

    int n, k;
	cin >> n >> k;
    fu(i, 1, n - 1){
        int l, r;
        cin >> l >> r;
        v[l].eb(r);
        v[r].eb(l);
    }
    dfs(1, 0);
    sort(all(res), greater<int>());
    ll ans = 0;
    fu(i, 0, k - 1) ans += res[i];
    cout << ans;
}