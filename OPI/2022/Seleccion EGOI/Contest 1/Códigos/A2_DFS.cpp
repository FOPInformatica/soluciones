#include<bits/stdc++.h>
using namespace::std;

const int N = 100000 + 5;

int n;
int ans = 0;
vector<int> G[N];

int DFS(int u, int p = -1){
	int maxi1 = 0, maxi2 = 0;
	for(int v : G[u]){
		if(v == p) continue;
		maxi2 = max(maxi2, 1 + DFS(v, u));
		if(maxi1 < maxi2) swap(maxi1, maxi2);
	}
	ans = max(ans, maxi1 + maxi2);
	return maxi1;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	DFS(1);
	printf("%d\n", ans + 1);
	return 0;
}