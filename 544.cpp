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

char A[3] = {'A', 'B', 'C'};

void dequy(int de, string s){
	if (de == 0){
		cout << s << endl;
		return ;
	}
	fu(i, 0, 2)
		if (s.empty() || s.back() != A[i]){
		s.pb(A[i]);
		dequy(de - 1, s);
		s.pop_back();
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

	int n;
	cin >> n;
	dequy(n, "");
}