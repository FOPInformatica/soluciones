#include<bits/stdc++.h>
using namespace::std;

const int N = 20 + 5;
const int MASK = 1 << 20;
const long long inf = 1e18;

int n;
int a[N];
int b[N];
long long memo[MASK];

long long solve(){
	for(int mask = 1, l = 1 << n; mask < l; mask++){
		int pos = n - __builtin_popcount(mask);
		memo[mask] = inf;
		for(int i = 0, p = 1; i < n; i++, p <<= 1){
			if(mask & p){
				memo[mask] = min(memo[mask], memo[mask ^ p] + abs(a[i] - b[pos]));
			}
		}
	}
	return memo[(1 << n) - 1];
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	for(int i = 0; i < n; i++) scanf("%d", b + i);
	printf("%lld\n", solve());
	return 0;
}