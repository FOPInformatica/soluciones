#include<bits/stdc++.h>
using namespace::std;

const int N = 10000+5;
const int MOD = 1000000000 + 7;

int n;

int add(int a, int b){
	return a + b < MOD? a + b : a + b - MOD;
}

int mul(long long a, long long b){
	return a * b % MOD;
}

int pow_mod(int a, int b){
	int r = 1;
	while(b > 0){
		if(b & 1) r = mul(r, a);
		a = mul(a,a);
		b >>= 1;
	}
	return r;
}

int fact(int x){
	int ans = 1;
	for(int i=1; i<=x; i++) ans = mul(ans, i);
	return ans;
}

int main(){
	scanf("%d",&n);
	if(n & 1){
		puts("0");
		return 0;
	}
	n >>= 1;
	int ans = mul(fact(2 * n), pow_mod(mul(fact(n+1), fact(n)), MOD-2));
	printf("%d\n",ans);
	return 0;
}