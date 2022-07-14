#include<bits/stdc++.h>
using namespace::std;

const int MOD = 1e9 + 7;
const int N = 10000 + 5;
const int B = 30 + 5;
const int K = 10;

int n, b, k;
int d[K];
int memo[N][B];

int main(){
	scanf("%d %d %d", &n, &b, &k);
	for(int i = 0; i < k; i++) scanf("%d", &d[i]);
	memo[n][0] = 1;
	for(int i = n - 1; i >= 0; i--){
    	for(int rem = 0; rem < b; rem++){
        	for(int j = 0; j < k; j++){
				int x = d[j];
            	int new_rem = (10 * rem + x) % b;
            	memo[i][rem] += memo[i + 1][new_rem];
            	if(memo[i][rem] >= MOD) memo[i][rem] -= MOD;
        	}
    	}
	}
	printf("%d\n", memo[0][0]);
	return 0;
}