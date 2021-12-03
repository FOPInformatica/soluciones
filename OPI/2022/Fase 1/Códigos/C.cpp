#include<bits/stdc++.h>
using namespace::std;

const int n = 4;

const int dy[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int dx[] = {2, -2, 1, -1, 2, -2, 1, -1};

bool valid_pos(int i, int j){
	return i >= 0 and j >= 0 and i < n and j < n;
}

int backtracking(int x, int y, int depth, vector<vector<bool>> &vis){
	if(depth < 0) return 0;
	if(x == n - 1 and y == n - 1){
		return 1;
	}
	int res = 0;
	for(int dir = 0; dir < 8; dir++){
		int vx = x + dx[dir];
		int vy = y + dy[dir];
		if(not valid_pos(vx, vy)) continue;
		if(vis[vx][vy]) continue;
		vis[vx][vy] = true;
		res += backtracking(vx, vy, depth - 1, vis);
		vis[vx][vy] = false;
	}
	return res;
}

int main(){
	vector<vector<bool>> vis(n, vector<bool>(n, false));
	vis[0][0] = true;
	printf("%d\n", backtracking(0, 0, 8, vis));
	return 0;
}
