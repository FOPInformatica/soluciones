#include<bits/stdc++.h>
using namespace::std;

const int N = 4000 + 5;

int n;
int m;
int p[N][N];
int a[N][N];
bool valid[N][N];
vector<int> c[N << 1];

int id(int i, int j){
	return i * m + j;
}

void BFS(int sx, int sy){
	memset(p, -1, sizeof p);
	vector<int> frontier;
	frontier.emplace_back(id(sx, sy));
	valid[sx][sy] = true;
	for(int i = 1; i < n + m - 1; i++){
		int min_nxt = INT_MAX;
		vector<int> new_frontier;
		for(auto e : frontier){
			int x = e / m;
			int y = e % m;
			int best_here = INT_MAX;
			if(x + 1 < n) best_here = min(best_here, a[x + 1][y]);
			if(y + 1 < m) best_here = min(best_here, a[x][y + 1]);
			min_nxt = min(min_nxt, best_here);
		}
		for(auto e : frontier){
			int x = e / m;
			int y = e % m;
			int best_here = INT_MAX;
			if(x + 1 < n) best_here = min(best_here, a[x + 1][y]);
			if(y + 1 < m) best_here = min(best_here, a[x][y + 1]);
			if(min_nxt == best_here){
				if(x + 1 < n and a[x + 1][y] == best_here){
					p[x + 1][y] = id(x, y);
					valid[x + 1][y] = true;
				}
				if(y + 1 < m and a[x][y + 1] == best_here){
					valid[x][y + 1] = true;
					p[x][y + 1] = id(x, y);
				}
			}
		}
		for(auto e : c[i]){
			int x = e / m;
			int y = e % m;
			if(valid[x][y]) new_frontier.emplace_back(id(x, y));
		}
		swap(frontier, new_frontier);
	}
}

void solve(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			c[i + j].emplace_back(id(i, j));
		}
	}
	BFS(0, 0);
	stack<int> S;
	int x = n - 1, y = m - 1;
	while(x > 0 or y > 0){
		S.emplace(a[x][y]);
		int e = p[x][y];
		x = e / m;
		y = e % m;
	}
	printf("%d", a[0][0]);
	while(!S.empty()){
		printf(" %d", S.top());
		S.pop();
	}
	puts("");
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	solve();
	return 0;
}
