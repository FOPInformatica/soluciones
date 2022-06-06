#include<bits/stdc++.h>
using namespace::std;

int n;
int m;

bool share(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first) return true;
	if(a.first == b.second) return true;
	if(a.second == b.first) return true;
	if(a.second == b.second) return true;
	return false;
}

int main(){
	scanf("%d %d", &n, &m);
	vector<pair<int, int>> v(m);
	for(int i = 0; i < m; i++) scanf("%d %d", &v[i].first, &v[i].second);
	int ans = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			if(share(v[i], v[j])) continue;
			if(v[i] > v[j]) continue;
			ans += v[j].first < v[i].second and v[i].second < v[j].second;
		}
	}
	printf("%d\n", ans);
	return 0;
}
