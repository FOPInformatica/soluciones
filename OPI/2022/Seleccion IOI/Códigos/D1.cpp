#include<bits/stdc++.h>
using namespace::std;

const int N = 5000 + 5;

int n;
char s[N];

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	int ans = 0;
	for(int i = 0; i < n; i++){
		bool has_x = false, has_o = false;
		for(int j = i; j < n; j++){
			if(s[j] == 'x') has_x = true;
			else has_o = true;
			if(has_x and has_o) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
