#include<bits/stdc++.h>
using namespace::std;

const int N = 8000 + 5;

int n;
int D[N];
vector<int> G[N];

int get_furthest(int src){
	memset(D, -1, sizeof D);
	queue<int> Q;
	Q.emplace(src);
	D[src] = 0;
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		for(int v : G[u]){
			if(~D[v]) continue; // ~D[v] da true si D[v] no es -1.
			D[v] = D[u] + 1;
			Q.emplace(v);
		}
	}
	return *max_element(D + 1, D + n + 1);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, get_furthest(i) + 1);
	}
	printf("%d\n", ans);
	return 0;
}