#include<bits/stdc++.h>
using namespace::std;

const int N = 1000000 + 5;

int n;
char s[N];
int frec[3 * N];

void add(int x){
	frec[x + N] += 1;
}

int get(int x){
	return frec[x + N];
}

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	add(0);
	int prefix = 0;
	long long ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'C') prefix -= 1;
		else prefix += 2;
		ans += get(prefix);
		add(prefix);
	}
	printf("%lld\n", ans);
	return 0;
}

