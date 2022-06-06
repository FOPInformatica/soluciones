#include<bits/stdc++.h>
using namespace::std;

int b[10];
int a[10];
int x[10];

int ask(int a, int b, int c){
	printf("? %d%d%d\n", a, b, c);
	fflush(stdout);
	char s[6];
	scanf("%s", s);
	if(s[0] == 'O') return 4;
	return atoi(s);
}

bool check(){
	for(int i = 0; i < 10; i++){
		int sum = a[i] + a[(i + 1) % 10] + a[(i + 2) % 10];
		if(sum != b[i]) return false;
	}
	return true;
}

void backtracking(int pos){
	if(pos == 10){
		if(check()){
			for(int i = 0; i < 10; i++) x[i] = a[i];
		}
		return;
	}
	a[pos] = 0;
	backtracking(pos + 1);
	a[pos] = 1;
	backtracking(pos + 1);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		bool found = false;
		for(int i = 0; i < 10 and !found; i++){
			b[i] = ask(i, (i + 1) % 10, (i + 2) % 10);
			if(b[i] == 4) found = true;
		}
		if(found) continue;
		backtracking(0);
		vector<int> v;
		for(int i = 0; i < 10; i++) if(x[i]) v.emplace_back(i);

		do{
			int r = ask(v[0], v[1], v[2]);
			if(r == 4) break;
		}while(next_permutation(v.begin(), v.end()));
	}
	return 0;
}
