#include<bits/stdc++.h>
using namespace::std;

const int M[10][10] = {
	{1,-2,1,1,-2,1,1,-2,1,1},
       	{1,1,-2,1,1,-2,1,1,-2,1},
       	{1,1,1,-2,1,1,-2,1,1,-2},
       	{-2,1,1,1,-2,1,1,-2,1,1},
       	{1,-2,1,1,1,-2,1,1,-2,1},
       	{1,1,-2,1,1,1,-2,1,1,-2},
       	{-2,1,1,-2,1,1,1,-2,1,1},
       	{1,-2,1,1,-2,1,1,1,-2,1},
       	{1,1,-2,1,1,-2,1,1,1,-2},
	{-2,1,1,-2,1,1,-2,1,1,1}
};

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
		vector<int> b(10);
		for(int i = 0; i < 10 and !found; i++){
			b[i] = ask(i, (i + 1) % 10, (i + 2) % 10);
			if(b[i] == 4) found = true;
		}
		if(found) continue;
		vector<int> x(10, 0);
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++) x[i] += M[i][j] * b[j];
		}
		vector<int> v;
		for(int i = 0; i < 10; i++) if(x[i]) v.emplace_back(i);

		do{
			if(ask(v[0], v[1], v[2]) == 4) break;
		}while(next_permutation(v.begin(), v.end()));
	}
	return 0;
}
