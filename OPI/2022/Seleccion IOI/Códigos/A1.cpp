#include<bits/stdc++.h>
using namespace::std;

int ask(int a, int b, int c){
	printf("? %d%d%d\n", a, b, c);
	fflush(stdout);
	char s[6];
	scanf("%s", s);
	return s[0] == 'O' ? 1 : 0;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		bool found = false;
		for(int i = 0; i < 10 and !found; i++){
			for(int j = 0; j < 10 and !found; j++){
				if(i == j) continue;
				for(int k = 0; k < 10 and !found; k++){
					if(i == k or j == k) continue;
					int r = ask(i, j, k);
					if(r) found = true;
				}
			}
		}
	}
	return 0;
}
