#include<bits/stdc++.h>
using namespace::std;

const int N = 1000000 + 5;

int n;
char s[N];

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	char last = ' ';
	int cnt = 0;
	long long ans = 1ll * n * (n + 1) / 2;
	for(int i = 0; i < n; i++){
		if(s[i] != last){		
			ans -= 1ll * cnt * (cnt + 1) / 2;
			cnt = 1;
		}
		else cnt++;
		last = s[i];
	}
	ans -= 1ll * cnt * (cnt + 1) / 2;
	printf("%lld\n", ans);
	return 0;
}
