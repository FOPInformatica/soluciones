#include<bits/stdc++.h>
using namespace::std;

const int N = 100000 + 5;

int n;
int a[N];
int b[N];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	for(int i = 0; i < n; i++) scanf("%d", b + i);
	sort(a, a + n);
	sort(b, b + n);
	long long ans = 0;
	for(int i = 0; i < n; i++) ans += abs(a[i] - b[i]);
	printf("%lld\n", ans);
	return 0;
}