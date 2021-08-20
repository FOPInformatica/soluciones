#include<bits/stdc++.h>
using namespace::std;

const int N = 200 + 5;
const int inf = 1e9;

int m;
int n;
int pos[N];
set<int> T[N];
bool vis[N][N][N];
int memo[N][N][N];
vector<int> G[3][N];

void toposort(){
	vector<int> deg(n, 0);
	queue<int> Q;
	for(int i = 0; i < n; i++){
		for(auto x : T[i]){
			deg[x] += 1;
		}
	}
	for(int i = 0; i < n; i++){
		if(deg[i] == 0){
			Q.emplace(i);
		}
	}
	vector<int> ans;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		ans.emplace_back(u);
		for(int v : T[u]){
			deg[v] -= 1;
			if(deg[v] == 0) Q.emplace(v);
		}
	}
	assert(ans.size() == n);
	for(int i = 0; i < n; i++) pos[ans[i]] = i;
}

int g(int a, int b, int c){
	if(a == b and b == c) return 0;
	if(a == b) return 1;
	if(a == c) return 1;
	return 0;
}

int DP(int x, int y, int z){
	if(x == n - 1 and y == n - 1 and z == n - 1) return 1;
	if(vis[x][y][z]) return memo[x][y][z];
	int ans = -inf;
	int min_order = min({pos[x], pos[y], pos[z]});
	if(pos[x] == min_order and x != n - 1){
		for(int v : G[0][x]){
			ans = max(ans, g(x, y, z) + DP(v, y, z));
		}
	}
	if(pos[y] == min_order and y != n - 1){
		for(int v : G[1][y]){
			ans = max(ans, g(y, x, z) + DP(x, v, z));
		}
	}
	if(pos[z] == min_order and z != n - 1){
		for(int v : G[2][z]){
			ans = max(ans, g(z, x, y) + DP(x, y, v));
		}
	}
	vis[x][y][z] = true;
	return memo[x][y][z] = ans;
}

int solve(){
	if(m == 2) return DP(0, 0, n - 1);
	return DP(0, 0, 0);
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int q;
		scanf("%d", &q);
		for(int j = 1; j <= q; j++){
			int u, v;
			scanf("%d %d", &u, &v);
			if(u < 1 or u > n) while(true);
			if(v < 1 or v > n) while(true);
			u--; v--;
			G[i][u].emplace_back(v);
			T[u].emplace(v);
		}
	}
	toposort();
	printf("%d\n", solve());
	return 0;
}