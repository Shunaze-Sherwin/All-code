#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define pa pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define endl '\n'
#define up upper_bound
#define low lower_bound
#define all(a) (a).begin(), (a).end()
#define bit(i, mask) (mask & (1 << i))
#define reset(a, val) memset(a, val, sizeof(val))
#define fu(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define int ll

constexpr int MOD = 1e9 + 7;
constexpr int mx = 1e5;
constexpr int inf = 1e18 + 15;

int A[mx + 5];
int T[mx + 5];
vector<int> IT[4*mx + 5];

void add(int &a, int b){a += b; if (a >= MOD) a -= MOD;};
void sub(int &a, int b){a -= b; if (a < 0) a += MOD;};
void mul(int &a, int b){a = (a%MOD) * (b%MOD) % MOD;}

void build(int id, int l, int r){
    if (l == r){
        IT[id] = {T[l]};
        return ;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    vector<int> temp(IT[id << 1].size() + IT[id << 1 | 1].size());
    IT[id] = temp;
    merge(all(IT[id << 1]), all(IT[id << 1 | 1]), IT[id].begin());
}

int get(int id, int l, int r, int u, int v, int vr, int val){
    if (v < l || r < u) return 0;
    if (u <= l && r <= v){
        int vt = up(all(IT[id]), vr - val) - IT[id].begin();
        return vt;
    }
    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v, vr, val) + get(id << 1 | 1, mid + 1, r, u, v, vr, val);
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

    int n, k;
    cin >> n >> k;
    fu(i, 1, n) cin >> A[i];
    T[0] = 0;
    fu(i, 1, n) T[i] = T[i - 1] + A[i];
    build(1, 1, n);
    int l = -1e14, r = 1e14;
    while (r >= l){
        int mid = (l + r) >> 1;
        int cnt = 0;
        fu(i, 1, n) 
            cnt += get(1, 1, n, 1, i - 1, T[i], mid) + (T[i] >= mid);
        if (cnt < k) r = mid - 1;
        else l = mid + 1;
    }
    cout << r;
}
/*

  /\__/\
 (=^.^= )
 (") (")_/

~~~-Sherwin-~~~

*/