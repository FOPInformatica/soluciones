#include<bits/stdc++.h>
using namespace::std;

const int N = 10 + 5;

int n;
int a[N];
int b[N];

long long cost(){
	long long cur = 0;
	for(int i = 0; i < n; i++){
		cur += abs(a[i] - b[i]);
	}
	return cur;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	for(int i = 0; i < n; i++) scanf("%d", b + i);
	sort(a, a + n);
	sort(b, b + n);
	long long ans = LLONG_MAX;
	do{
		ans = min(ans, cost());
	}while(next_permutation(a, a + n));
	printf("%lld\n", ans);
	return 0;
}