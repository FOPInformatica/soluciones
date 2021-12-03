#include<bits/stdc++.h>
using namespace::std;

const int N = 100000 + 5;

int n;
int f;
int v;
int x[N];
int cnt[N];

void sort(){
	int at = 1;
	for(int i = 0; i < N; i++){
		while(cnt[i]-- > 0){
			x[at++] = i;
		}
	}
}

int main(){
	scanf("%d %d %d", &f, &v, &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", x + i);
		cnt[x[i]]++;
	}
	sort();
	int mini = 1e9 + 10;
	int last_memo = 0;
	for(int i = 1; i <= n; i++){
		int d = x[i] * v;
		int cur = min(f + last_memo, mini + d + f);
		if(mini > last_memo - d) mini = last_memo - d;
		last_memo = cur;
	}
	printf("%d\n", last_memo);
	return 0;
}
