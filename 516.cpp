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

int L4[] = {0, 0, 1, -1};
int R4[] = {1, -1, 0, 0};

int n, m;
char A[10][10];
string s;

struct gt{
    int a, b, vt;
};

bool check(int x, int y){
    queue<gt> qu;
    qu.push({x, y, 0});
    while (!qu.empty()){
        gt temp = qu.front();
        qu.pop();
        if (s[temp.vt] != A[temp.a][temp.b]) continue;
        if (temp.vt == s.size() - 1) return true;
        fu(i, 0, 3){
            int k1 = temp.a + R4[i];
            int k2 = temp.b + L4[i];
            if (k1 > 0 && k2 > 0 && k1 <= n && k2 <= m) qu.push({k1, k2, temp.vt + 1});
        }
    }
    return false;
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
    fu(i, 1, n)
        fu(j, 1, m) cin >> A[i][j];
    cin >> s;
    fu(i, 1, n)
        fu(j, 1, m)
            if (check(i, j)){
                cout << "YES";
                return 0;
            }
    cout << "NO";
}