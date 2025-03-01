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
const int mx = 1e5;

bool vi[10] = { };
bool kt[50] = { };
bool k[50] = { };
int n, de = 0;

void dequy(int vt){
	if (vt == n + 1){
		++de;
		return ;
	}
	fu(i, 1, n)
		if (!vi[i] && !kt[vt - i + n] && !k[vt + i]){
			vi[i] = true;
			kt[vt - i + n] = true;
			k[vt + i] = true;
			dequy(vt + 1);
			vi[i] = false;
			kt[vt - i + n] = false;
			k[vt + i] = false;
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

	cin >> n;
	dequy(1);
	cout << de;
}