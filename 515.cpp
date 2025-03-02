#include <bits/stdc++.h>

using namespace std;

long long A[1000005];

int main(){
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> A[i];
	while (q--){
		long long val;
		cin >> val;
		cout << lower_bound(A + 1, A + n + 1, val) - A << endl;
	}
}