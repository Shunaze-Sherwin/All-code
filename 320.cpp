#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5;

long long A[mx + 5];
long long T1[mx + 5];
long long T2[mx + 5];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> A[i];
	T1[0] = 0;
	T2[0] = 0;
	for (long long i = 1; i <= n; ++i){
		T1[i] = T1[i - 1] + A[i];
		T2[i] = T2[i - 1] + A[i]*i;			
	}
	while (q--){
		long long l, r;
		cin >> l >> r;
		cout << (T2[r] - T2[l - 1]) - (l - 1)*(T1[r] - T1[l - 1]) << '\n';
	}
}