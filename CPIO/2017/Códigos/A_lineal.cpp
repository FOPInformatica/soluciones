#include<bits/stdc++.h>
using namespace::std;

const int N = 1000 + 5;

int n;
int k;
int a[N];
char s[N];
int dif[N];

int solve(){
	int res = 0;
	for(int i = 1; i <= n; i++){
		dif[i] ^= dif[i - 1];
		a[i] ^= dif[i];
		if(a[i]) continue;
		if(i + k - 1 <= n){
			a[i] ^= 1;
			dif[i] ^= 1;
			dif[i + k] ^= 1;
			res += 1;
		}
		if(!a[i]) return -1;
	}
	return res;
}

int main(){
	scanf("%s %d", s + 1, &k);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i++){
		if(s[i] == 'F') a[i] = 1;
		else a[i] = 0;
	}
	int ans = solve();
	printf("%d\n", ans);
	return 0;
}