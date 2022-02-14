#include<bits/stdc++.h>
using namespace::std;

const int N = 2e6 + 1;
const int MAX = 2e5;
const int MOD = 1e9 + 7;

int n;
int m;
int len;
int d[N];
int cnt[N];
int fix[N];
bitset<N> used;
int primes[MAX];
bitset<N> composite;

int get_divisors(int x, int p){
	int e = 1;
	while(x % p == 0){
		e++;
		x /= p;
	}
	return d[x] * (e + 1);
}

void init(int n){
	d[1] = 1;
	for(int i = 2; i <= n; i++){
		if(!composite[i]){
			d[i] = 2;
			primes[len++] = i;
		}
		for(int j = 0; j < len; j++){
			int p = primes[j];
			if(i * p > n) break;
			composite[i * p] = 1;
			d[i * p] = d[i] * 2;
			if(i % p == 0){
				d[i * p] = get_divisors(i, p);
				break;
			}
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	init(n);
	for(int i = 1; i <= n; i++) cnt[d[i]]++;
	for(int i = 1; i <= m; i++){
		int x, to;
		scanf("%d %d", &to, &x);
		if(x > n or d[x] != d[to]){
			puts("0");
			return 0;
		}
		fix[to] = x;
		cnt[d[x]]--;
	}
	int ans = 1;
	for(int i = 1; i <= n; i++){
		if(fix[i]) continue;
		ans = (1ll * cnt[d[i]] * ans) % MOD;
		cnt[d[i]]--;
	}
	printf("%d\n", ans);
	return 0;
}
