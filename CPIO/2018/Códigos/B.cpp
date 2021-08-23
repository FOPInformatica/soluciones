#include<bits/stdc++.h>
using namespace::std;

long long a, b;

long long f(long long x){
	return x / 5;
}

int main(){
	scanf("%lld %lld",&a,&b);
	printf("%lld\n",f(b) - f(a-1));
	return 0;
}