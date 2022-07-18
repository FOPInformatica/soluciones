#include<bits/stdc++.h>
using namespace::std;

const int N = 200000 + 5;

int n;
int q;
int m;
int a[N];
vector<tuple<int, int, int>> queries;

int get_index(int at){
	for(int i = queries.size() - 1; i >= 0; i--){
		int op, l, r;
		tie(op, l, r) = queries[i];
		if(at < l or r < at) continue;
		if(op == 1){
			if(at == l) at = r;
			else at--;
		}
		else at = r + l - at;
	}
	return at;
}

int main(){
	scanf("%d %d %d", &n, &q, &m);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	while(q--){
		int op, l, r;
		scanf("%d %d %d", &op, &l, &r);
		queries.emplace_back(make_tuple(op, l, r));
	}
	for(int i = 1; i <= m; i++){
		int x;
		scanf("%d", &x);
		printf("%d%c", a[get_index(x)], " \n"[i == m]);
	}
	return 0;
}

