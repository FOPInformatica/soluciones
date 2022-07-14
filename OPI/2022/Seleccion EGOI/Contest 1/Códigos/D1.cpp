#include<bits/stdc++.h>
using namespace::std;

const int MOD = 1e9 + 7;

int digits(int x){
	return x < 10 ? 1 : 1 + digits(x / 10);
}

int main(){
	int l, r;
	scanf("%d %d", &l, &r);
	int ans = 0;
	for(int i = l; i <= r; i++){
		ans += (1ll * i * digits(i)) % MOD;
		if(ans >= MOD) ans -= MOD;
	}
	printf("%d\n", ans);
	return 0;
}