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

	string s;
	cin >> s;
	stringstream ss(s);
	stack<ll> st;
	ll a;
	char c;
	ss >> a;
	st.push(a);
	while (ss >> c >> a){
		if (c == '-') st.push(-a);
		if (c == '+') st.push(a);
		if (c == '*'){
			ll val = st.top()*a;
			st.pop();
			st.push(val);
		}
	}
	ll t = 0;
	while (!st.empty()){
		t += st.top();
		st.pop();
	}
	cout << t;
}