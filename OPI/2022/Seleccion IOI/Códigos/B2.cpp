#include<bits/stdc++.h>
using namespace::std;

const int N = 1000 + 5;

int n;
int m;
int cnt[N];
vector<int> L[N];

long long solve(){
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		for(auto r : L[i]){
			for(int j = i + 1; j < r; j++) ans += cnt[j];
		}
		for(auto r : L[i]) cnt[r] += 1;
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
