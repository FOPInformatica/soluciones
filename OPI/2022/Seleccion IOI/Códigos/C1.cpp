#include<bits/stdc++.h>
using namespace::std;

int n, b;

long long get_prod(int x){
	return x < 10 ? x : get_prod(x / 10) * (x % 10);
}

int check(int x){
	long long prod = get_prod(x);
	return x == b + prod;		
}

int main(){
	scanf("%d %d", &n, &b);
	int ans = 0;
	for(int x = 1; x <= n; x++) ans += check(x);
	printf("%d\n", ans);
	return 0;
}
