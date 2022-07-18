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
int nxt[LOG][N];
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

void build_next_array(){
	for(int i = 1; i <= n; i++){
		for(int j = 0, p = 1; j < LOG; j++, p <<= 1){
			if(b[i] & p) nxt[j][i] = i;
			else nxt[j][i] = nxt[j][i - 1];
		}
	}
}

void compute_memo(int i){
	memo[i] = inf;
	vector<pair<int, int>> changes;
	for(int j = 0, p = 1; j < LOG; j++, p <<= 1){
		if(leftmost[i] <= nxt[j][i]) changes.emplace_back(make_pair(nxt[j][i] + 1, p));
	}
	sort(changes.begin(), changes.end(), greater<pair<int, int>>());
	int l = 0, r = 0;
	int cur_val = 0;
	while(l < changes.size()){
		memo[i] = min(memo[i], cur_val + memo[changes[l].first - 1]);
		while(r < changes.size() and changes[l].first == changes[r].first){
			cur_val |= changes[r].second;
			r++;
		}
		l = r;
	}
	memo[i] = min(memo[i], cur_val + memo[leftmost[i] - 1]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= n; i++) scanf("%d", b + i);
	get_leftmost();
	build_next_array();
	for(int i = 1; i <= n; i++) compute_memo(i);
	printf("%lld\n", memo[n]);
	return 0;
}

