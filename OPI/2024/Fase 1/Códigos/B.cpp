#include<bits/stdc++.h>
using namespace::std;
 
const int MOD = 998244353;
const int N = 10000000 + 5;
const int MAX = 1000000 + 5;

int mul(long long a, long long b) {
	return a * b % MOD;
}

int pow_mod(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}

int n;
int k;
int P;
int memo[MAX];
int last[MAX];
bitset<N> composite;

void init() {
	composite[1] = 1;
	for(int i = 3; i * i < N; i += 2) {
		if(not composite[i]) {
			for(int j = i * i; j < N; j += i) {
				composite[j] = 1;
			}
		}
	}
}

bool prime(int x) {
	if(x % 2 == 0) return x == 2;
	return !composite[x];
}

int count_primes() {
	int p = 1;
	for(int i = 1; i < k; i++) p *= 10;
	int res = 0;
	for(int i = p; i < 10 * p; i++) res += prime(i);
	return res;
}

int DP(int pos, int head, vector<vector<int>> &memo) {
	if(pos == n) return 1;
	if(~memo[pos][head]) return memo[pos][head];
	int res = 0;
	for(int i = 0; i <= 9; i++) {
		if(not prime(10 * head + i) or 10 * head + i < P) continue;
		res += DP(pos + 1, 10 * (head % (P / 10)) + i, memo);
		if(res >= MOD) res -= MOD;
	}
	return memo[pos][head] = res;
}

bool has_zero(int x) {
	while(x) {
		if(x % 10 == 0) return true;
		x /= 10;
	}
	return false;
}

int solve() {
	P = 1;
	for(int i = 1; i < k; i++) P *= 10;
	vector<vector<int>> memo(n, vector<int>(P, -1));
	int res = 0;
	for(int i = P / 10; i < P; i++) {
		res += DP(k - 1, i, memo);
		if(res >= MOD) res -= MOD;
	}
	return res;
}

int main(){
	init();
	scanf("%d %d", &n, &k);
	if(k == 1) printf("%d\n", pow_mod(count_primes(), n));
	else if(n == k) printf("%d\n", count_primes());
	else printf("%d\n", solve());
	return 0;
}
