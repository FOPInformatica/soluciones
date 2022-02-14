#include<bits/stdc++.h>
using namespace::std;

const int N = 700 + 5;
const int MOD = 1e9 + 7;

int C[N][N];
int ac[N][N];
int memo[N][N];

void init(){
	for(int i = 1; i < N; i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++){
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			if(C[i][j] >= MOD) C[i][j] -= MOD;
		}
	}
}

int query(int n, int h){
	if(h >= n - 1) return ac[n][n - 1];
	return ac[n][h];
}

void preprocess(int limit){
	memo[1][0] = 1;
	ac[1][0] = 1;
	for(int n = 2; n <= limit; n++){
		for(int root = 1; root <= n; root++){
			int L = root - 1;
			int R = n - root;
			int coef = C[n - 1][L];
			if(L == 0){
				for(int h = 0; h < R; h++){
					memo[n][h + 1] += memo[R][h];
					if(memo[n][h + 1] >= MOD) memo[n][h + 1] -= MOD;
				}
			}
			else if(R == 0){
				for(int h = 0; h < L; h++){
					memo[n][h + 1] += memo[L][h];
					if(memo[n][h + 1] >= MOD) memo[n][h + 1] -= MOD;
				}
			}
			else{
				for(int hL = 1; hL < L; hL++){
					int cur = (1ll * memo[L][hL] * query(R, hL - 1)) % MOD;
					cur = (1ll * cur * coef) % MOD;
					memo[n][hL + 1] += cur;
					if(memo[n][hL + 1] >= MOD) memo[n][hL + 1] -= MOD;
				}
				for(int hR = 1; hR < R; hR++){
					int cur = (1ll * memo[R][hR] * query(L, hR - 1)) % MOD;
					cur = (1ll * cur * coef) % MOD;
					memo[n][hR + 1] += cur;
					if(memo[n][hR + 1] >= MOD) memo[n][hR + 1] -= MOD;
				}
				for(int h = 0; h < min(L, R); h++){
					int cur = (1ll * memo[L][h] * memo[R][h]) % MOD;
					cur = (1ll * cur * coef) % MOD;
					memo[n][h + 1] += cur;
					if(memo[n][h + 1] >= MOD) memo[n][h + 1] -= MOD;
				}
			}
		}
		ac[n][0] = memo[n][0];
		for(int h = 1; h < n; h++){
			ac[n][h] = ac[n][h - 1] + memo[n][h];
			if(ac[n][h] >= MOD) ac[n][h] -= MOD;
		}
	}
}

int getAns(int limit){
	int ans = 0;
	for(int i = 0; i < limit; i++){
		ans += (1ll * memo[limit][i] * i) % MOD;
		if(ans >= MOD) ans -= MOD;
	}
	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	init();
	preprocess(n);
	printf("%d\n", getAns(n));
	return 0;
}
