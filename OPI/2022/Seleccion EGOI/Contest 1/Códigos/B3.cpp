#include<bits/stdc++.h>
using namespace::std;

const int B = 1000 + 5;
const int MOD = 1e9 + 7;

int pot = 10;
int b, k;
long long n;
int C[B];
int R[B];
int M[B];

void multiply(int id){
	for(int i = 0; i < b; i++) C[i] = 0;
	for(int i = 0; i < b; i++){
    	for(int j = 0; j < b; j++){
        	int r = (i * pot + j) % b;
        	C[r] += (1ll * (id == 0 ? M[i] : R[i]) * M[j]) % MOD;
        	if(C[r] >= MOD) C[r] -= MOD;
    	}
	}
	for(int i = 0; i < b; i++){
    	(id == 0 ? M[i] : R[i]) = C[i];
	}
}

void fast_expo(long long e){
	while(e){
		if(e & 1) multiply(1);
    	multiply(0);
    	pot = (pot * pot) % b;
    	e >>= 1;
	}
}

int main(){
	scanf("%lld %d %d", &n, &b, &k);
	for(int i = 0; i < k; i++){
    	int x;
		scanf("%d", &x);
    	M[x % b] += 1;
	}
	R[0] = 1;
	fast_expo(n);
	printf("%d\n", R[0]);
	return 0;
}