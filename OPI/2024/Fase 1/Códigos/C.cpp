#include<bits/stdc++.h>
using namespace::std;
 
int n;
int a;
int b;
int m;

int f(int x) {
	return (1ll * x * a + b) % m;
}	

int main(){
	int t;
	scanf("%d", &t);
	while(t--) {
		int x0;
		scanf("%d %d %d %d %d", &n, &a, &b, &m, &x0);
		vector<int> S(n), L(n), R(n);
		S[0] = x0;
		for(int i = 1; i < n; i++) {
			x0 = f(x0);
			S[i] = x0;
		}
		int maxi = -1;
		for(int i = 0; i < n; i++) {
			L[i] = maxi;
			maxi = max(maxi, S[i]);
		}
		maxi = -1;
		for(int i = n - 1; i >= 0; i--) {
			R[i] = maxi;
			maxi = max(maxi, S[i]);
		}
		long long res = 0;
		for(int i = 0; i < n; i++) {
			int mini = min(L[i], R[i]);
			if(mini < S[i]) continue;
			res += mini - S[i];
		}
		printf("%lld\n", res);
	}
	return 0;
}
