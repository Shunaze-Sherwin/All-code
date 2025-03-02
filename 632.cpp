#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int mx = 2e7;

long long A[mx + 5];
long long x, y, n, ans = 0, de = 0;
bool kt[mx + 5] = { };

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (long long i = 1; i*i <= n; ++i){
        ++de;
        A[de] = i;
        kt[i] = true;
    }
    long long m = sqrt(n);
    for (long long i = m; i >= 1; --i){
        long long temp = n/i;
        if (temp > m || !kt[temp]){
            ++de;
            A[de] = temp;
        }
    }
    A[0] = -1;
    long long vtd = 1;
    for (int i = de; i >= 1; --i)
        if (A[i] != A[i - 1]){
            x = A[i];
            y = A[i] + 1;
            if (x%2 == 0) x /= 2;
            else y /=2;
            x %= mod;
            y %= mod;

            long long tmp1 = x*y%mod; 

            long long vtc = n/A[i];

            x = (vtc + vtd);
            y = (vtc - vtd + 1);
            if (x%2 == 0) x /= 2;
            else y /=2;
            x %= mod;
            y %= mod;

            long long tmp2 = x*y%mod; 

            ans = (ans + tmp1*tmp2%mod)%mod;
            vtd = vtc + 1;
        }
    cout << ans;
}