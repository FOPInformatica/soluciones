#include<bits/stdc++.h>
using namespace::std;

const int n = 87087;

int main(){
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(n % i == 0 and i % 2 == 1) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
