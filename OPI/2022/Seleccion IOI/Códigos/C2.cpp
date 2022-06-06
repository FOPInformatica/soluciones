#include<bits/stdc++.h>
using namespace::std;

long long n, b;
int cnt_n[10];
int used[10];

bool check_zero(long long x){
	if(x < 10) return false;
	if(x % 10 == 0) return true;
	return check_zero(x / 10);
}

bool check(long long P){
	P += b;
	memset(cnt_n, 0, sizeof cnt_n);
	while(P){
		cnt_n[P % 10] += 1;
		P /= 10;
	}
	for(int i = 0; i < 10; i++) if(used[i] != cnt_n[i]) return false;
	return true;
}

long long backtracking(int len, int last, long long prod){
	if(last == 10) return 0;
	if(prod + b > n) return 0;
	if(len == 0) return check(prod);
	long long ans = backtracking(len, last + 1, prod);
	used[last] += 1;
	ans += backtracking(len - 1, last, prod * last);
	used[last] -= 1;
	return ans;
}

int main(){
	scanf("%lld %lld", &n, &b);
	long long ans = check_zero(b) and n >= b;
	for(int l = 1; l <= 11; l++){
		ans += backtracking(l, 1, 1ll);
	}
	printf("%lld\n", ans);
	return 0;
}
