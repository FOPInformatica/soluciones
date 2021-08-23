#include<bits/stdc++.h>
using namespace::std;

const int inf = 1000000000;

int n;

int main(){
	scanf("%d", &n);
	int max_dif = -inf;
	int total = 0;
	int kiko = 0;
	for(int i = 1; i <= n; i++){
		int p, k;
		scanf("%d %d", &p, &k);
		max_dif = max(max_dif, p - k);
		total += p;
		kiko += k;
	}
	puts(2 * (kiko + max_dif) > total ? "Puede" : "No puede");
	return 0;
}