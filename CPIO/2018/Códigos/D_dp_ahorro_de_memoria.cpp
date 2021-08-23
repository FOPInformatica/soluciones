#include<bits/stdc++.h>
using namespace::std;

const int MOD = 1000000000 + 7;
const int N = 10000 + 5;

int n;
int memo[N];
int last[N];

int solve(){
	last[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i + 1; j++) memo[j] = 0;
		for(int j = 0; j <= i; j++){
			memo[j + 1] += last[j];
			if(memo[j + 1] >= MOD) memo[j + 1] -= MOD;
			if(j > 0) memo[j - 1] += last[j];
			if(memo[j - 1] >= MOD) memo[j - 1] -= MOD;
		}
		for(int j = 0; j <= i + 1; j++) last[j] = memo[j];
	}
	return last[0];
}

int main(){
	scanf("%d", &n);
	if(n & 1){
		puts("0");
		return 0;
	}
	printf("%d\n", solve());
	return 0;
}