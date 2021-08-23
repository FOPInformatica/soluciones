#include<bits/stdc++.h>
using namespace::std;

const int N = 100000 + 5;

int n;
int a[N];
int last[N];
int prefix[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		prefix[i] = (prefix[i - 1] + a[i]) % n;
	}
	for(int i = 1; i < n; i++) last[i] = -1;
	int l = -1, r = -1;
	for(int i = 1; i <= n; i++){
		int R = prefix[i];
		if(last[R] != -1){
			l = last[R] + 1;
			r = i;
		}
		last[R] = i;
	}
	printf("%d\n", r - l + 1);
	for(int i = l; i <= r; i++) printf("%d%c", a[i], " \n"[i == r]);
	return 0;
}