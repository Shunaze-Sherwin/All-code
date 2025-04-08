#include <bits/stdc++.h>
 
using namespace std;

int n;
vector<int> v[100005];
int dp[100005];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int l, r;
        cin >> l >> r;
        v[r].push_back(l);
    }
    dp[0] = 0;
    for (int i = 1; i <= 100000; ++i){
        dp[i] = dp[i-1];
        for (int j : v[i]) dp[i] = max(dp[i], dp[j - 1] + i - j + 1);
    }
    cout << dp[100000];
}