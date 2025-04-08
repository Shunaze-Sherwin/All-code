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
#define int ll

const int mod = 1e9 + 7;
const int mx = 1e3;

ld vi[mx + 5];
vector<pa> tmp;
int de, n;
ld mid;

ld kc(int x, int y, int u, int v){
	int t1 = abs(x - u), t2 = abs(y - v);
	return t1*t1 + t2*t2;
}

void check(){
	queue<int> qu;
	qu.push(1);
	vi[1] = mid;
	ld val = 2*mid;
	val *= val;
	while (!qu.empty()){
		int temp = qu.front();
		qu.pop();
		fu(i, 1, n)
			if (vi[i] != mid && kc(tmp[temp].fi, tmp[temp].se, tmp[i].fi, tmp[i].se) <= val){
				vi[i] = mid;
				qu.push(i);
				++de;
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

	cin >> n;
	tmp.eb(0, 0);
	int u, v;
	fu(i, 1, n){
		cin >> u >> v;
		tmp.eb(u, v);
	}
	ld l = 1, r = inf;
	while (r - l >= 1e-7){
		mid = (l + r)/2;
		de = 1;
		check();
		if (de == n) r = mid;
		else l = mid;
	}
	cout << setprecision(6) << fixed << l;
}