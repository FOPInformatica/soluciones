#include<bits/stdc++.h>
using namespace::std;

const int MOD = 1e9 + 7;

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}

int suma(unsigned long long x){
	unsigned long long l = x, r = x + 1;
	if(l % 2 == 0) l /= 2;
	else r /= 2;
	return mul(l % MOD, r % MOD);
}

int f(unsigned long long x){
	int ans = 0;
	int len = 1;
	unsigned long long l = 1, r = 9;
	while(l <= x){
		unsigned long long limit = min(x, r);
		ans += mul(len, (suma(limit) + MOD - suma(l - 1))) % MOD;
		if(ans >= MOD) ans -= MOD;
		l *= 10;
		r = 10 * r + 9;
		len += 1;
	}
	return ans;
}

int main(){
	unsigned long long l, r;
	scanf("%llu %llu", &l, &r);
	printf("%d\n", (f(r) + MOD - f(l - 1)) % MOD);
	return 0;
}