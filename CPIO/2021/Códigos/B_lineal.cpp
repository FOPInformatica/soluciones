#include<bits/stdc++.h>
using namespace::std;

const int N = 200000 + 5;

int n;
int m;
int len;
int L[N];
int R[N];
int t[N];
int low[N];
int high[N];

void solve(){
	int posA = 1;
	int posB = 1;
	int l = -2;
	int r = -2;
	while(posA <= n and posB <= m){
		while(posB <= m and t[posB] <= r) posB += 1;
		if(L[posA] <= t[posB]){
			if(L[posA] <= r + 1){
				r = max(r, R[posA]);
			}
			else{
				if(l >= 1){
					low[len] = l;
					high[len] = r;
					len += 1;
				}
				l = L[posA];
				r = R[posA];
			}
			posA += 1;
		}
		else{
			if(t[posB] == r + 1){
				r += 1;
			}
			else{
				if(l >= 1){
					low[len] = l;
					high[len] = r;
					len += 1;
				}
				l = t[posB];
				r = t[posB];
			}
			posB += 1;
		}
	}
	while(posA <= n){
		if(L[posA] <= r + 1){
			r = max(r, R[posA]);
		}
		else{
			if(l >= 1){
				low[len] = l;
				high[len] = r;
				len += 1;
			}
			l = L[posA];
			r = R[posA];
		}
		posA += 1;
	}
	while(posB <= m){
		while(posB <= m and t[posB] <= r) posB += 1;
		if(posB > m) break;
		if(t[posB] == r + 1){
			r += 1;
		}
		else{
			if(l >= 1){
				low[len] = l;
				high[len] = r;
				len += 1;
			}
			l = t[posB];
			r = t[posB];
		}
		posB += 1;
	}
	if(l >= 1){
		low[len] = l;
		high[len] = r;
		len += 1;
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d %d", L + i, R + i);
	for(int i = 1; i <= m; i++) scanf("%d", t + i);
	solve();
	printf("%d\n", len);
	for(int i = 0; i < len; i++){
		printf("%d %d\n", low[i], high[i]);
	}
	return 0;
}