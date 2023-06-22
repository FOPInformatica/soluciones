#include<bits/stdc++.h>
using namespace::std;

const int N = 30000 + 5;
const int LOG = 16;

struct DSU {
    vector<int> par;
    vector<int> sizes;
    int one_indexed;

    DSU(int n, int one_indexed = 0) : one_indexed(one_indexed) {
        par.resize(n);
        sizes.resize(n);
        for(int i = 0; i < n; i++) par[i] = i, sizes[i] = 1;
    }

    int get(int x) {
        return par[x] == x ? x : par[x] = get(par[x]);
    }

    bool equal_set(int x, int y) {
        x -= one_indexed; y -= one_indexed;
        return get(x) == get(y);
    }

    void join(int a, int b) {
        a -= one_indexed; b -= one_indexed;
        a = get(a);
        b = get(b);
        if(a == b) return;
        if(sizes[a] > sizes[b]) swap(a, b);
        par[a] = b;
        sizes[b] += sizes[a];
    }
};

int n;
int q;
int T;
int h[N];
int a[N];
int ft[N];
int in[N];
int out[N];
int path[N];
bool vis[N];
int ST[N][LOG];
vector<int> G[N];
vector<tuple<int, int, int>> queries;

void update(int pos, int val) {
    pos++;
    while(pos <= n) {
        ft[pos] += val;
        pos += (-pos) & pos;
    }
}

int get_sum(int pos) {
    pos++;
    int res = 0;
    while(pos) {
        res += ft[pos];
        pos &= pos - 1;
    }
    return res;
}

void build_forest() {
    DSU Solver(n, 1);
    for(auto e : queries) {
        int op, u, v;
        tie(op, u, v) = e;
        if(op == 1) {
            if(!Solver.equal_set(u, v)) {
                G[u].emplace_back(v);
                G[v].emplace_back(u);
                Solver.join(u, v);
            }
        }
    }
}

void compute(int u, int p) {
    ST[u][0] = p;
    for(int d = 1, pot = 2; pot <= h[u]; d++, pot <<= 1) {
        ST[u][d] = ST[p][0];
        p = ST[p][d];
    }
}

void DFS(int u, int p = -1) {
    compute(u, p);
    in[u] = T++;
    vis[u] = true;
    for(int v : G[u]) {
        if(v == p) continue;
        h[v] = h[u] + 1;
        path[v] = path[u] + a[v];
        DFS(v, u);
    }
    out[u] = T - 1;
}

int go_up(int u, int d) {
    while(d) {
        int k = __builtin_ctz(d);
        d &= d - 1;
        u = ST[u][k];
    }
    return u;
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
    return get_sum(in[u]) + get_sum(in[v]) - 2 * get_sum(in[l]) + a[l];
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        int op, u, v;
        scanf("%d %d %d", &op, &u, &v);
        queries.emplace_back(make_tuple(op, u, v));
    }
    build_forest();
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        path[i] = a[i];
        DFS(i);
    }
    for(int i = 1; i <= n; i++) {
        update(in[i], path[i]);
        update(in[i] + 1, -path[i]);
    }
    DSU Solver(n, 1);
    for(int i = 0; i < q; i++) {
        int op, u, v;
        tie(op, u, v) = queries[i];
        if(op == 1) {
            if(!Solver.equal_set(u, v)) {
                Solver.join(u, v);
                puts("1");
            }
            else puts("0");
        }
        else if(op == 2) {
            int dif = v - a[u];
            update(in[u], dif);
            update(out[u] + 1, -dif);
            a[u] = v;
        }
        else {
            if(!Solver.equal_set(u, v)) {
                puts("-1");
            }
            else { 
                printf("%d\n", query(u, v));
            }
        }
    }
    return 0;
}
