#include<bits/stdc++.h>
using namespace::std;

const int MAX = 1000000 + 5;
const long long inf = 1e18;
const int N = 500000 + 5;
const int LOG = 20;

int n;
int a[N];
int b[N];
bool vis[MAX];
int ST[LOG][N];
int leftmost[N];
long long memo[N];

void get_leftmost(){
	int to = n;
	for(int i = n; i >= 1; i--){
		while(to >= 1 and !vis[a[to]]){
			vis[a[to]] = true;
			to--;
		}
		leftmost[i] = to + 1;
		vis[a[i]] = false;
	}
}


void build_sparse_table(){
	for(int i = 1; i <= n; i++) ST[0][i] = b[i];
	for(int d = 1, dis = 1; 2 * dis <= n; d++, dis <<= 1){
		for(int i = 1; i + 2 * dis - 1 <= n; i++){
			ST[d][i] = ST[d - 1][i] | ST[d - 1][i + dis];
		}
	}
}

int query(int l, int r){
	int d = r - l + 1;
	int k = 31 - __builtin_clz(d);
	int p = 1 << k;
	return ST[k][l] | ST[k][r - p + 1];
}

void compute_memo(int i){
	memo[i] = inf;
	int l = i;
	while(leftmost[i] <= l){
		int val = query(l, i);
		int lo = leftmost[i], hi = l;
		while(lo < hi){
			int mi = lo + (hi - lo) / 2;
			if(query(mi, i) != val) lo = mi + 1;
			else hi = mi;
		}
		memo[i] = min(memo[i], val + memo[lo - 1]);
		l = lo - 1;
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= n; i++) scanf("%d", b + i);
	get_leftmost();
	build_sparse_table();
	for(int i = 1; i <= n; i++) compute_memo(i);
	printf("%lld\n", memo[n]);
	return 0;
}

