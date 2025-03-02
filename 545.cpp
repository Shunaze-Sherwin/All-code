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
#define log __lg
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define fu(i,a,b) for (int i = a; i <= b; ++i)
#define fd(i,a,b) for (int i = a; i >= b; --i)
#define all(a) a.begin(), a.end()

const int mod = 1e9 + 7;
const int mx = 1e6;

ll n, k, mid;
ll A[mx + 5];
ll T[mx + 5] = { };
int cs[mx + 5] = { };
int temp[mx + 5] = { };
bool kt = false;
 
void dequy(int vt){
	if (vt == n + 1){
		fu(i, 1, n) temp[i] = cs[i];
		kt = true;
		return ;
	}
	fu(j, 1, k)
		if (T[j] + A[vt] <= mid){
			cs[vt] = j;
			T[j] += A[vt];
			dequy(vt + 1);
			if (kt) return ;
			T[j] -= A[vt];
		}
}

signed main(){

 	#define name "Sherwin"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

	#define name "APROBOT"
    if (fopen(name".INP", "r")){
        freopen(name".INP", "r", stdin);
        freopen(name".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	ll t = 0;
	fu(i, 1, n) {
		cin >> A[i];
		t += A[i];
	}
	if (t%k == 0){
		mid = t/k;
		dequy(1);
		if (kt) {
			fu(i, 1, n) cout << cs[i] << char(32);
			return 0;
		}
	}
	cout << "ze";
}