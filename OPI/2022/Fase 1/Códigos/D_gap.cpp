#include<bits/stdc++.h>
using namespace::std;

const int N = 100000 + 5;

int n;
int F;
int V;
int a[N];
int gap[N];

int main(){
	scanf("%d %d %d", &F, &V, &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", a + i);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i + 1 <= n; i++){
		gap[i] = a[i + 1] - a[i];
	}
	sort(gap + 1, gap + n, greater<int>());
	long long ans = 1ll * n * F;
	long long sum_gaps = accumulate(gap, gap + n, 0ll);
	for(int i = 0; i < n; i++){
		sum_gaps -= gap[i];
		ans = min(ans, sum_gaps * V + 1ll * (i + 1) * F);
	}
	printf("%lld\n", ans);
	return 0;
}
