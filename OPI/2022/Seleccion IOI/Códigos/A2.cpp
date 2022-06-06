#include<bits/stdc++.h>
using namespace::std;

int ask(int a, int b, int c){
	printf("? %d%d%d\n", a, b, c);
	fflush(stdout);
	char s[6];
	scanf("%s", s);
	if(s[0] == 'O') return 4;
	return atoi(s);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		bool found = false;
		vector<int> v;
		for(int i = 0; i < 10 and !found; i++){
			for(int j = i + 1; j < 10 and !found; j++){
				for(int k = j + 1; k < 10 and !found; k++){
					int r = ask(i, j, k);
					if(r == 4){
						found = true;
					}
					else if(r == 3){
						v = {i, j, k};
					}
				}
			}
		}
		if(found) continue;
		do{
			if(ask(v[0], v[1], v[2]) == 4) break;
		}while(next_permutation(v.begin(), v.end()));
	}
	return 0;
}
