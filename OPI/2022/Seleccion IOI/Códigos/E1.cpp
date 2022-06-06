#include<bits/stdc++.h>
using namespace::std;

const int N = 2000 + 5;

int n;
int m;
int q;
bool vis[N];
vector<int> G[N];

void DFS(int u){
	vis[u] = true;
	for(int v : G[u]){
		if(vis[v]) continue;
		DFS(v);
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].emplace_back(v);
	}
	while(q--){
		int u, v;
		scanf("%d %d", &u, &v);
		memset(vis, 0, sizeof vis);
		DFS(u);
		puts(vis[v] ? "Si" : "No");
	}
	return 0;
}
