#include <bits/stdc++.h>
#define eb emplace_back
#define re(x, y, z) for (int x=y; x<z; ++x)
#define trav(v, x) for (auto v : x)
using namespace std;
using vi = vector<int>;
using ll = long long;
using vll = vector<ll>;
using iii = pair<pair<int, int>, int>;
const int maxn = 2e3 + 10;
struct Node {
	int to, t, c;
	Node() {}
	Node(int to, int t, int c):
		to(to), t(t), c(c) {}
};
vector<Node> g[maxn];
int n, m;

vll dikjstra(int s) {
	priority_queue<iii, vector<iii>, greater<iii>> Q;
	vll res(n+1, LLONG_MAX);
	vi tim(n+1, INT_MAX);
	Q.push({{0, 0}, s});
	while (!Q.empty()) {
		auto q = Q.top(); Q.pop();
		int v = q.second;
		int t = q.first.second, c = q.first.first;
		res[v] = min(res[v], t*1ll*c);
		if (tim[v] < t) continue;
		else tim[v] = t;
		trav(e, g[v]) {
			Q.push({{c+e.c, t+e.t}, e.to});
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (res[i] == LLONG_MAX) res[i] = -1;
	}
	return res;
} 

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, t, c;
		scanf("%d%d%d%d", &a, &b, &t, &c);
		g[a].eb(b, t, c);
		g[b].eb(a, t, c);
	}
	vll res = dikjstra(1);
	for (int i = 2; i <= n; ++i) {
		printf("%lld\n", res[i]);
	}
	return 0;
}
