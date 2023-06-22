#include<bits/stdc++.h>
using namespace::std;

const int N = 30000 + 5;
const int LOG = 16;

int n;
int q;
int a[N];
int h[N];
int root[N];
int path[N];
int ST[N][LOG];
vector<int> G[N];
vector<int> comp[N];

void compute(int u, int p) {
    ST[u][0] = p;
    for(int d = 1, pot = 2; pot <= h[u]; d++, pot <<= 1) {
        ST[u][d] = ST[p][0];
        p = ST[p][d];
    }
}

void DFS(int u, int p) {
    compute(u, p);
    for(int v : G[u]) {
        if(v == p or root[v] != root[u]) continue;
        h[v] = h[u] + 1;
        path[v] = path[u] + a[v];
        DFS(v, u);
    }
}

void merge(int u, int v) {
    if(comp[root[u]].size() > comp[root[v]].size()) swap(u, v);
    G[v].emplace_back(u);
    G[u].emplace_back(v);
    h[u] = h[v] + 1;
    path[u] = path[v] + a[u];
    DFS(u, v);
    int root_u = root[u];
    while(!comp[root_u].empty()) {
        int x = comp[root_u].back(); comp[root_u].pop_back();
        root[x] = root[v];
        comp[root[v]].emplace_back(x);
    }
}

int go_up(int a, int d) {
    while(d) {
        int k = __builtin_ctz(d);
        d &= d - 1;
        a = ST[a][k];
    }
    return a;
}

int lca(int u, int v) {
    if(h[u] < h[v]) swap(u, v);
    u = go_up(u, h[u] - h[v]);
    if(u == v) return u;
    for(int k = LOG - 1, p = 1 << (LOG - 1); k >= 0; k--, p >>= 1) {
        if(p > h[u]) continue;
        if(ST[u][k] != ST[v][k]) {
            u = ST[u][k];
            v = ST[v][k];
        }
    }
    return ST[u][0];
}

int query(int u, int v) {
    int l = lca(u, v);
    return path[u] + path[v] - 2 * path[l] + a[l];
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        comp[i].emplace_back(i);
        scanf("%d", a + i);
        root[i] = i;
        h[i] = 0;
        path[i] = a[i];
        ST[i][0] = -1;
    }
    scanf("%d", &q);
    while(q--) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            int u, v;
            scanf("%d %d", &u, &v);
            if(root[u] == root[v]) puts("0");
            else {
                merge(u, v);
                puts("1");
            }
        }
        else if(op == 3) {
            int u, v;
            scanf("%d %d", &u, &v);
            if(root[u] != root[v]) puts("-1");
            else printf("%d\n", query(u, v));
        }
        else assert(false);
    }
    return 0;
}
