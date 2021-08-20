#include<bits/stdc++.h>
using namespace::std;

long long gcd(long long a, long long b){
	while(b){
		a %= b;
		swap(a, b);
	}
	return a;
}

long long n, m, a;

int main(){
	scanf("%lld %lld %lld", &n, &m, &a);
	a -= a / n + a / m - (a / n) / m;
	printf("%lld\n", a);
	return 0;
}