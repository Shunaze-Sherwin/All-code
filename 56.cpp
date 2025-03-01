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

struct gt{
	int l, r, kq;
};

gt A[15];

int de = 0;
int n, m, q;
int B[10] = { };

void dequy(int vt){
	if (vt > n){
		fu(i, 1, q)
			if (B[A[i].l] + B[A[i].r] != A[i].kq) return ;
		++de;
		return ;
	}
	fu(i, 1, m){
		B[vt] = i;
		dequy(vt + 1);
		B[vt] = 0;
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

	cin >> n >> m >> q;
	fu(i, 1, q) cin >> A[i].l >> A[i].r >> A[i].kq;
	dequy(1);
	cout << de;
}