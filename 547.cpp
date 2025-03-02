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
#define gcd __gcd
#define log __lg
#define all(a) a.begin(), a.end()
#define upper upper_bound
#define lower lower_bound
#define search binary_search
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)

const int mod = 1e9 + 7;
const int mx = 1e3;

int L[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int R[] = {0, -1, 1, -1, 1, 0, -1, 1};

bool boom[25][25] = { };
int A[25][25];
bool kt = false;
int n, m;

bool check(int x, int y){
	fu(i, 0, 7)
		if (A[x + R[i]][y + L[i]] <= 0) return false;
	return true;
}

bool Acheck(){
	fu(i, 1, n)
		fu(j, 1, m)
			if (A[i][j] != 0) return false;
	return true;
}
 
void dequy(int x, int y){
	if (y == m + 1){
        ++x;
        y = 1;
    }
	if (x == n + 1){
		kt = Acheck();
		return ;
	}
    if (x > 1 && y > 1 && A[x - 1][y - 1] >= 2) return ;
	boom[x][y] = true;
    fu(i, 0, 7) {
        --A[x + R[i]][y + L[i]];
        if (A[x + R[i]][y + L[i]] < 0){
            fd(j, i, 0) ++A[x + R[j]][y + L[j]];
            boom[x][y] = false;
            break;
        }
    }
	dequy(x, y + 1);
    if (kt) return ;
    if (boom[x][y]){
        fu(i, 0, 7) ++A[x + R[i]][y + L[i]];
        boom[x][y] = false;
        dequy(x, y + 1);
        if (kt) return ;
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

	cin >> n >> m;
    fu(i, 0, n + 1)
        fu(j, 0, m + 1) A[i][j] = 15;
	fu(i, 1, n)
		fu(j, 1, m) cin >> A[i][j];
	dequy(1, 1);
	fu(i, 1, n){
		fu(j, 1, m) cout << boom[i][j] << char(32);
		cout << endl;
	}
}