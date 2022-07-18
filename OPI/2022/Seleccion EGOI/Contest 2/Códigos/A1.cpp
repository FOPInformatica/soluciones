#include<bits/stdc++.h>
using namespace::std;

const int N = 1000 + 5;

int n;
char s[N];

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	int ans = 0;
	for(int i = 0; i < n; i++){
		int p1 = 0, p2 = 0;
		for(int j = i; j < n; j++){
			if(s[j] == 'C') p1++;
			else p2 += 2;
			if(p1 == p2) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}

