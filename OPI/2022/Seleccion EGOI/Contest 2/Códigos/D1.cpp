#include<bits/stdc++.h>
using namespace::std;

int main(){
	int one_column = 0;
	int two_columns = 3;
	while(true){
		char c = getchar();
		if(c == 'W') break;
		getchar();
		if(c == 'I'){
			printf("1 %d\n", one_column / 2 + 1);
			one_column++;
		}
		else{
			printf("0 %d\n", two_columns);
			two_columns += 2;
		}
		fflush(stdout);
	}
	return 0;
}

