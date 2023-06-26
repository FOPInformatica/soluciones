#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
struct Node {
    int u, id;
};
vector<Node> g[maxn];

void add_edge(int x, int y, int i) {
    g[x].push_back({y, i});
    g[y].push_back({x, i});
}

struct S {
    int len;
    int diam;

    S(int l=0, int d=0): len(l), diam(d) {}

    void add_edge() {
        len += 1;
        max(len, diam);
    }

    S operator+(const S& other) {
        return S(
            max(len, other.len),
            max({diam, other.diam, len + other.len}));
    }
} dp[maxn];
int ans[maxn];

S dfs(int x, int p) {
    dp[x] = S(0, 0);
    for (Node& e : g[x]) {
        if (e.u == p) {
            swap(e, g[x].back());
            if (e.u == p) continue;
        }
        S dp_u = dfs(e.u, x);
        dp_u.add_edge();
        dp[x] = dp[x] + dp_u;
    }
    if (p != 0) g[x].pop_back();
    return dp[x];
}

void dfs_reroot(int x, int p, S out) {
    vector<S> suf;
    for (Node e : g[x]) {
        S dp_u = dp[e.u];
        dp_u.add_edge();
        suf.push_back(dp_u);
    }
    suf.push_back(S(0, 0));
    for (int i=(int)suf.size()-2; i>=0; --i) {
        suf[i] = suf[i] + suf[i+1];
    }
    S pref(0, 0);
    for (int i=0; i<g[x].size(); ++i) {
        auto [u, id] = g[x][i];
        S new_out = out + (pref + suf[i+1]);
        S dp_u = dp[u];
        ans[id] = new_out.diam + 1 + dp_u.diam;
        new_out.add_edge();
        dfs_reroot(u, x, new_out);
        dp_u.add_edge();
        pref = pref + dp_u;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i=0; i<n-1; ++i) {
        int a, b;
        cin>>a>>b;
        add_edge(a, b, i);
    }
    dfs(1, 0);
    dfs_reroot(1, 0, S(-n, -n));
    for (int i=0; i<n-1; ++i) {
        cout<<ans[i]<<'\n';
    }
    return 0;
}
