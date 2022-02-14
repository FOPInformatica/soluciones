#include<bits/stdc++.h>
using namespace::std;

const int N = 4000 + 10;
const int inf = 1e9;

int n;
int m;
int v;
int x[N];
int y[N];
int h[N];
int w[N];
int len_x;
int len_y;
int par[N];
int width[N];
int sizes[N];
int val_x[N];
int val_y[N];
int memo[N][N];

void compress(int* x, int *values, int &len, int limit){
	len = 0;
	set<int> S;
	S.emplace(0);
	S.emplace(limit);
	for(int i = 0; i < v; i++){
		S.emplace(x[2 * i]);
		S.emplace(x[2 * i + 1] + 1);
	}
	map<int, int> id;
	for(int x : S){
		values[len] = x;
		id[x] = len++;
	}
	for(int i = 0; i < v; i++){
		x[2 * i] = id[x[2 * i]];
		x[2 * i + 1] = id[x[2 * i + 1] + 1];
	}
}

void update_rectangle(int i){
	int x1 = x[2 * i], x2 = x[2 * i + 1];
	int y1 = y[2 * i], y2 = y[2 * i + 1];
	memo[x1][y1] += 1;
	memo[x2][y2] += 1;
	memo[x1][y2] -= 1;
	memo[x2][y1] -= 1;
}

void compute_cells(){
	for(int i = 0; i < len_x; i++){
		for(int j = 0; j < len_y; j++){
			if(i) memo[i][j] += memo[i - 1][j];
			if(j) memo[i][j] += memo[i][j - 1];
			if(i and j) memo[i][j] -= memo[i - 1][j - 1];
		}
	}
	for(int i = 0; i < len_x; i++){
		for(int j = 0; j < len_y; j++){
			if(memo[i][j]) memo[i][j] = 0;
			else memo[i][j] = 1;
		}
	}
}

int get(int x){
	return par[x] == x ? x : par[x] = get(par[x]);
}

void join(int a, int b){
	a = get(a);
	b = get(b);
	if(a == b) return;
	if(sizes[a] > sizes[b]) swap(a, b);
	par[a] = b;
	sizes[b] += sizes[a];
	width[b] += width[a];
}

int get_max_square(){
	vector<int> perm(len_y - 1);
	iota(perm.begin(), perm.end(), 0);
	sort(perm.begin(), perm.end(), [&] (int i, int j){
		return h[i] > h[j];
	});
	for(int i = 0; i + 1 < len_y; i++){
		width[i] = val_y[i + 1] - val_y[i];
		par[i] = i;
		sizes[i] = 1;
	}
	int res = 0;
	for(int i : perm){
		if(i and h[i - 1] >= h[i]) join(i, i - 1);
		if(i + 1 < perm.size() and h[i + 1] >= h[i]) join(i, i + 1);
		res = max(res, min(h[i], width[get(i)]));
	}
	return res;
}

int solve(){
	int ans = 0;
	for(int i = 0; i + 1 < len_x; i++){
		for(int j = 0; j + 1 < len_y; j++){
			int usize = val_x[i + 1] - val_x[i];
			if(!memo[i][j]) h[j] = 0;
			else h[j] += usize;
		}
		int cand = get_max_square();
		if(ans < cand) ans = cand;
	}
	return ans;
}

int main(){
	scanf("%d %d %d", &n, &m, &v);
	for(int i = 0; i < v; i++){
		scanf("%d %d %d %d", &x[2 * i], &x[2 * i + 1], &y[2 * i], &y[2 * i + 1]);
	}
	compress(x, val_x, len_x, n);
	compress(y, val_y, len_y, m);
	for(int i = 0; i < v; i++){
		update_rectangle(i);
	}
	compute_cells();
	printf("%d\n", solve());
	return 0;
}
