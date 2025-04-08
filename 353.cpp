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

bool color[mx + 5] = { };
bool vi[mx + 5] = { };
vector<int> v[mx + 5];
int cost[mx + 5][2] = { };

void bfs(int vt){
    vi[vt] = true;
    ++cost[vt][color[vt]];
    queue<int> qu;
    qu.push(vt);
    while (!qu.empty()){
        int temp = qu.front();
        qu.pop();
        for (int i : v[temp])
            if (!vi[i]){
                vi[i] = true;
                cost[i][0] = cost[temp][0];
                cost[i][1] = cost[temp][1];
                ++cost[i][color[i]];
                qu.push(i);
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

    int n;
	cin >> n;
    fu(i, 1, n){
        char c;
        cin >> c;
        color[i] = (c == '1' ? 1 : 0);
    }
    fu(i, 1, n - 1){
        int l, r;
        cin >> l >> r;
        v[l].eb(r);
        v[r].eb(l);
    }
    bfs(1);
    int ans = 0;
    fu(i, 1, n)
        if (cost[i][0] > cost[i][1]) ++ans;
    cout << ans;
}