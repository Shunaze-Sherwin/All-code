#include <bits/stdc++.h>

using namespace std;

#define inf 1e18
#define ll long long
#define ull unsigned long long
#define pa pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define gcd __gcd
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define fu(i,a,b) for (int i = a; i <= b; ++i)
#define fd(i,a,b) for (int i = a; i >= b; --i)
#define all(a) a.begin(), a.end()

const int mod = 1e9 + 7;
const int mx = 5e6;

ll n, k;
vector<int> v;
bool vi[mx + 5] = { };

void dequy(){
	if (v.size() >= k){
		for (int i : v) cout << i << char(32);
		cout << endl;
		return ;
	}
	fu(i, 1, n)
		if (!vi[i]){
			v.pb(i);
			vi[i] = true;
			dequy();
			v.pop_back();
			vi[i] = false;
		}
}

signed main(){

 	#define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

	#define name "CAU2"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	dequy();
}