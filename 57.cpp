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

int A[10][10] = { };
bool vh[10][10] = { };
bool vc[10][10] = { };
bool vi[3][3][10] = { };
bool kt = false;
int de = 0;
 
void dequy(int x, int y){
	if (y > 9){
		y = 1;
		++x;
	}
	if (x > 9){
		++de;
		kt = true;
		return ;
	}
	while (A[x][y] != 0){
		++y;
		if (y > 9) {
			y = 1;
			++x;
		}
		if (x > 9){
			++de;
			kt = true;
			return;
		}
	}
	fu(i, 1, 9)
		if (!vh[x][i] && !vc[y][i] && !vi[(x - 1)/3][(y - 1)/3][i]){
			A[x][y] = i;
			vh[x][i] = true;
			vc[y][i] = true;
            vi[(x - 1)/3][(y - 1)/3][i] = true;
			dequy(x, y + 1);
			if (kt) return ;
			A[x][y] = 0;
            vi[(x - 1)/3][(y - 1)/3][i] = false;
			vh[x][i] = false;
			vc[y][i] = false;
		}
	if (kt) return ;
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

    fu(i, 1, 9)
		fu(j, 1, 9) {
			int val;
			cin >> val;
			A[i][j] = val;
			vh[i][val] = true;
			vc[j][val] = true;
			vi[(i - 1)/3][(j - 1)/3][val] = true;
		}		
	dequy(1, 1);
	fu(i, 1, 9){
		fu(j, 1, 9) cout << A[i][j] << char(32);
		cout << endl;
	}
}