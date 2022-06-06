#include<bits/stdc++.h>
using namespace::std;

const int N = 100000 + 5;
const int B = 64;

int n;
int m;
int q;
int U[N];
int V[N];
vector<int> G[N];
unsigned long long vis[N];
unsigned long long pot[64];

bool is_set(unsigned long long x, int b){
	return (x & pot[b]) > 0;
}

int main(){
	pot[0] = 1;
	for(int i = 1; i < 64; i++) pot[i] = pot[i - 1] << 1;
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		G[a].emplace_back(b);
	}
	for(int i = 0; i < q; i++){
		scanf("%d %d", U + i, V + i);
		U[i]--; V[i]--;
	}
	for(int i = 0; i * B < q; i++){
		int l = i * B;
		int r = min(q, l + B);
		vector<unsigned long long> vis(n, 0);
		for(int j = l; j < r; j++) vis[V[j]] |= pot[j - l];
		for(int u = n - 1; u >= 0; u--){
			for(int v : G[u]) vis[u] |= vis[v];
		}
		for(int j = l; j < r; j++){
			puts(is_set(vis[U[j]], j - l) ? "Si" : "No");
		}
	}
	return 0;
}
