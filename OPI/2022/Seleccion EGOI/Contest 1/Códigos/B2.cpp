#include<bits/stdc++.h>
using namespace::std;

const int B = 30 + 5;
const int MOD = 1e9 + 7;

int b, k;
long long n;
int C[B][B];
int R[B][B];
int M[B][B];

void multiply(int id){
	for(int i = 0; i < b; i++){
    	for(int j = 0; j < b; j++){
        	C[i][j] = 0;
        	for(int k = 0; k < b; k++){
    			C[i][j] += (1ll * (id == 0 ? M[i][k] : R[i][k]) * M[k][j]) % MOD;
            	if(C[i][j] >= MOD) C[i][j] -= MOD;
        	}
    	}
	}
	for(int i = 0; i < b; i++){
    	for(int j = 0; j < b; j++){
    		(id == 0 ? M[i][j] : R[i][j]) = C[i][j];
    	}
	}
}

void fast_expo(long long b){
	while(b){
		if(b & 1) multiply(1);
    	multiply(0);
    	b >>= 1;
	}
}

int main(){
	scanf("%lld %d %d", &n, &b, &k);
	for(int i = 0; i < k; i++){
    	int x;
		scanf("%d", &x);
    	for(int rem = 0; rem < b; rem++){
    		M[rem][(10 * rem + x) % b] += 1;
    	}
	}
	for(int i = 0; i < b; i++) R[i][i] = 1;
	fast_expo(n);
	printf("%d\n", R[0][0]);
	return 0;
}