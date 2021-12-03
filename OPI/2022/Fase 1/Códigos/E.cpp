#include<bits/stdc++.h>
using namespace::std;

const int N = 2000 + 5;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n;
int m;
char s[N][N];
int deg[N][N];
int dis[N][N];
bool vis[N][N];

bool valid_pos(int i, int j){
	return i >= 0 and j >= 0 and i < n and j < m;
}

bool neighbor(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2) == 1;
}

bool is_border(int i, int j){
	return i == 0 or j == 0 or i == n - 1 or j == m - 1;
}

pair<int, int> get_furthest(int sx, int sy, bool border = false){
	memset(dis, -1, sizeof dis);
	dis[sx][sy] = 0;
	queue<pair<int, int>> Q;
	Q.emplace(make_pair(sx, sy));
	while(!Q.empty()){
		int ux = Q.front().first;
		int uy = Q.front().second;
		Q.pop();
		for(int k = 0; k < 4; k++){
			int vx = ux + dx[k];
			int vy = uy + dy[k];
			if(not valid_pos(vx, vy)) continue;
			if(s[vx][vy] == '#'){
				if(is_border(vx, vy) and (not border or not neighbor(sx, sy, vx, vy)) and dis[vx][vy] == -1) dis[vx][vy] = dis[ux][uy] + 1;
				continue;
			}
			else if(~dis[vx][vy]) continue;
			dis[vx][vy] = dis[ux][uy] + 1;
			Q.emplace(make_pair(vx, vy));
		}
	}
	int rx = 0, ry = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(not is_border(i, j)) continue;
			if(border and neighbor(sx, sy, i, j)) continue;
			if(dis[i][j] <= dis[rx][ry]) continue;
			rx = i;
			ry = j;
		}
	}
	return make_pair(rx, ry);
}

void fill(){
	queue<pair<int, int>> Q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s[i][j] == '#') continue;
			int border = 0;
			for(int k = 0; k < 4; k++){
				int x = i + dx[k];
				int y = j + dy[k];
				if(not valid_pos(x, y)) continue;
				if(s[x][y] == '#'){
					if(is_border(x, y)) border++;
				}
				else deg[i][j]++;
			}
			if(border) vis[i][j] = true;
			if(deg[i][j] <= 1 and !border){
				Q.emplace(make_pair(i, j));
			}
		}
	}
	while(!Q.empty()){
		int ux = Q.front().first;
		int uy = Q.front().second;
		Q.pop();
		s[ux][uy] = '#';
		for(int k = 0; k < 4; k++){
			int vx = ux + dx[k];
			int vy = uy + dy[k];
			if(not valid_pos(vx, vy)) continue;
			if(s[vx][vy] == '#') continue;
			if(vis[vx][vy]) continue;
			deg[vx][vy]--;
			if(deg[vx][vy] == 1){
				Q.emplace(make_pair(vx, vy));
			}
		}
	}
}

void solve(){
	int x0, y0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s[i][j] == '#') continue;
			x0 = i;
			y0 = j;
		}
	}
	auto [x1, y1] = get_furthest(x0, y0);
	for(int k = 0; k < 4; k++){
		int vx = x1 + dx[k];
		int vy = y1 + dy[k];
		if(not valid_pos(vx, vy)) continue;
		if(s[vx][vy] == '.'){
			x1 = vx;
			y1 = vy;
			break;
		}
	}
	int best_dis = -1;
	tuple<int, int, int, int> res = make_tuple(n, m, n, m);
	for(int k = 0; k < 4; k++){
		int vx = x1 + dx[k];
		int vy = y1 + dy[k];
		if(not valid_pos(vx, vy)) continue;
		if(!is_border(vx, vy)) continue;
		auto [x2, y2] = get_furthest(vx, vy, true);
		int cur_dis = dis[x2][y2];
		if(make_pair(vx, vy) > make_pair(x2, y2)){
			swap(vx, x2);
			swap(vy, y2);
		}
		if(cur_dis > best_dis){
			best_dis = cur_dis;
			res = make_tuple(vx, vy, x2, y2);
		}
		else if(cur_dis == best_dis){
			if(make_tuple(vx, vy, x2, y2) < res){
				res = make_tuple(vx, vy, x2, y2);
			}
		}
	}
	printf("%d %d\n", get<0>(res), get<1>(res));
	printf("%d %d\n", get<2>(res), get<3>(res));
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%s", s[i]);
	}
	fill();
	solve();
	return 0;
}
