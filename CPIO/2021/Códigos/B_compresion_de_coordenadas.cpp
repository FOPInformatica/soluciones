#include<bits/stdc++.h>
using namespace::std;

const int N = 100000 + 5;
const int M = 400000 + 5;

int n;
int m;
int len;
int L[N];
int R[N];
int t[N];
int nodes;
int val[M];
int low[M];
int high[M];
bool vis[M];

void compress(){
	int l = 0;
	for(int i = 0; i < n; i++){
		val[l++] = L[i];
		val[l++] = R[i] + 1;
	}
	for(int i = 0; i < m; i++){
		val[l++] = t[i];
		val[l++] = t[i] + 1;
	}
	sort(val, val + l);
	int nl = 0;
	for(int i = 0; i < l; i++){
		if(i == 0 or val[i] != val[nl - 1]){
			val[nl++] = val[i];
		}
	}
	l = nl;
	int id = 0;
	int pos = 0;
	for(int i = 0; i < n; i++){
		while(pos < l and val[pos] < L[i]){
			pos++;
		}
		L[i] = pos;
		while(pos < l and val[pos] < R[i] + 1){
			pos++;
		}
		R[i] = pos;
	}
	id = 0;
	pos = 0;
	for(int i = 0; i < m; i++){
		while(pos < l and val[pos] < t[i]){
			pos++;
		}
		t[i] = pos;
	}
	nodes = l;
	for(int i = 0; i < n; i++){
		for(int j = L[i]; j < R[i]; j++) vis[j] = true;
	}
	for(int i = 0; i < m; i++){
		vis[t[i]] = true;
	}
}

void solve(){
	int l = 0, r = 0;
	while(l < nodes){
		while(l < nodes and not vis[l]) l += 1;
		if(l == nodes) break;
		r = l;
		while(r < nodes and vis[r]) r += 1;
		low[len] = val[l];
		high[len] = val[r] - 1;
		len += 1;
		l = r;
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d %d", L + i, R + i);
	}
	for(int i = 0; i < m; i++){
		scanf("%d", t + i);
	}
	compress();
	solve();
	printf("%d\n", len);
	for(int i = 0; i < len; i++){
		printf("%d %d\n", low[i], high[i]);
	}
	return 0;
}