#include<bits/stdc++.h>
using namespace::std;

bool two(char c){
	return c == 'O' or c == 'S' or c == 'Z';
}

int main(){
	int pos_two = 5;
	while(true){
		char c = getchar();
		if(c == 'W') break;
		getchar();
		if(c == 'I'){
			puts("1 1");
		}
		else if(two(c)){
			printf("1 %d\n", pos_two);
			pos_two += 2;
		}
		else{
			puts("2 2");
		}
		fflush(stdout);
	}
	return 0;
}

