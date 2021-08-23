#include<bits/stdc++.h>
using namespace::std;

const int N = 1000 + 5;

int n;
int k;
int a[N];
char s[N];

int main(){
	scanf("%s %d", s + 1, &k);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i++){
		if(s[i] == 'F') a[i] = 1;
		else a[i] = 0;
	}
	int ans = 0;
	for(int i = 1; i + k - 1 <= n; i++){
		if(a[i]) continue;
		for(int j = i; j < i + k; j++){
			a[j] ^= 1;
		}
		ans += 1;
	}
	bool can = true;
	for(int i = 1; i <= n; i++) can &= a[i] == 1;
	if(can) printf("%d\n",ans);
	else puts("-1");
	return 0;
}