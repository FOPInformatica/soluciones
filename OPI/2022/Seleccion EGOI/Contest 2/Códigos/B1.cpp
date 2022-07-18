#include<bits/stdc++.h>
using namespace::std;

const int N = 1000 + 5;

int n;
int q;
int m;
int a[N];

int main(){
	scanf("%d %d %d", &n, &q, &m);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	while(q--){
		int op, l, r;
		scanf("%d %d %d", &op, &l, &r);
		if(op == 1){
			for(int i = r; i > l; i--){
				swap(a[i], a[i - 1]);
			}
		}
		else{
			reverse(a + l, a + r + 1);
		}
	}
	for(int i = 1; i <= m; i++){
		int x;
		scanf("%d", &x);
		printf("%d%c", a[x], " \n"[i == m]);
	}
	return 0;
}

