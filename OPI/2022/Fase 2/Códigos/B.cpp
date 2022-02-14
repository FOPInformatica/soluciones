#include<bits/stdc++.h>
using namespace::std;

const int N = 100000 + 5;

int n;
int a[N];
int id[N];
int head[N];
bool memo[N];
bool last[N];
int new_id[N];
int sorted_by_a[N];
int sorted_by_id[N];

void init(){
	for(int i = 1; i <= n; i++){
		id[i] = a[i];
		sorted_by_a[i] = i;
	}
	sort(sorted_by_a + 1, sorted_by_a + n + 1, [&] (int i, int j){
		return a[i] < a[j];
	});
	for(int i = 1; i <= n; i++) sorted_by_id[i] = sorted_by_a[i];
}

void build_new_level(int len){
	for(int i = 1; i <= n; i++){
		int x = sorted_by_a[i] - len + 1;
		if(x >= 1) head[id[x]]++;
	}
	int sum = 1;
	for(int i = 1; i <= n; i++){
		sum += head[i];
		head[i] = sum - head[i];
	}
	for(int i = 1; i <= n; i++){
		int x = sorted_by_a[i] - len + 1;
		if(x >= 1) sorted_by_id[head[id[x]]++] = x;
	}
	new_id[sorted_by_id[1]] = 1;
	for(int i = 2; i + len - 1 <= n; i++){
		if(id[sorted_by_id[i - 1]] != id[sorted_by_id[i]]){
			new_id[sorted_by_id[i]] = new_id[sorted_by_id[i - 1]] + 1;
		}
		else{
			int pre = a[sorted_by_id[i - 1] + len - 1];
			int cur = a[sorted_by_id[i] + len - 1];
			new_id[sorted_by_id[i]] = new_id[sorted_by_id[i - 1]] + (pre != cur);
		}
	}
	for(int i = 1; i <= n; i++){
		head[i] = 0;
		id[i] = new_id[i];
	}
}

bool can(int len){
	memset(memo, 0, sizeof memo);
	int min_that_has = n + 1;
	bool res = false;
	for(int i = n - len + 1; i >= 1; i--){
		if(i + len <= n and last[i + len]) min_that_has = min(min_that_has, id[i + len]);
		if(min_that_has <= min(id[i], id[i + 1])) memo[i] = res = true;
	}
	for(int i = 1; i <= n; i++) last[i] = memo[i];
	return res;
}

int solve(){
	init();
	int ans = 1;
	for(int i = 1; i <= n; i++) last[i] = true;
	while(can(ans + 1)){
		ans += 1;
		build_new_level(ans);
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	printf("%d\n", solve());
	return 0;
}
