#include<bits/stdc++.h>
using namespace::std;

const int N = 300000 + 5;

int n;
int m;
int ft[N];
vector<int> L[N];

void update(int pos){
	while(pos <= n){
		ft[pos] += 1;
		pos += (-pos) & pos;
	}
}

int get_sum(int pos){
	int res = 0;
	while(pos > 0){
		res += ft[pos];
		pos &= pos - 1;
	}
	return res;
}

int query(int l, int r){
	if(l > r) return 0;
	return get_sum(r) - get_sum(l - 1);
}

long long solve(){
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		for(auto r : L[i]) ans += query(i + 1, r - 1);
		for(auto r : L[i]) update(r);
	}
	return ans;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		L[l].emplace_back(r);
	}
	printf("%lld\n", solve());
	return 0;
}
