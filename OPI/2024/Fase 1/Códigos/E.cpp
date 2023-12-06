#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
struct dsu_rollback {
 
    vector<int> parent;
    vector<size_t> subtree_sz;
    stack<int> changes;
    vector<pair<int, ll>> mst;
    int N;
 
    dsu_rollback(int n): N(n) {
        mst.emplace_back(0, 0);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        subtree_sz.resize(n, 1);
    }
 
    int get_root(int x) {
        return parent[x] != x ? get_root(parent[x]) : x;
    }
 
    void merge(int u, int v, int e) {
        u = get_root(u); v = get_root(v);
        if (u == v) {
            mst.emplace_back(mst.back());
            return changes.push(-1);
        }
        if (subtree_sz[u] < subtree_sz[v]) swap(u, v);
        subtree_sz[u] += subtree_sz[v];
        parent[v] = u;
        changes.push(v);
        auto [c, w] = mst.back();
        mst.emplace_back(c+1, w+e);
    } 
 
    bool same(int u, int v) {
        return get_root(u) == get_root(v);
    }
 
    void undo() {
        if (changes.empty()) return;
        if (changes.top() >= 0) {
            int v = changes.top();
            subtree_sz[parent[v]] -= subtree_sz[v];
            parent[v] = v;          
        }
        changes.pop();
        mst.pop_back();
    }
 
    ll weight(int pos) {
        if (pos < 0) pos += (int)mst.size();
        return mst[pos].first == N-1 ? mst[pos].second : 0;
    }
};
 
struct Query {
    int t, u, v;
};
vector<Query> Q;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    dsu_rollback dsu(n);
    Q.resize(m);
    for (int i=0; i<m; ++i) {
        string s;
        cin>>s;
        if (s[0] == 'A') {
            int u, v;
            cin>>u>>v;
            Q[i] = {0, --u, --v};
        } else if (s[0] == 'D') {
            int k;
            cin>>k;
            Q[i] = {1, k, 0};
        } else {
            Q[i] = {2, 0, 0};
        }
    }
    for (int i=0; i<m; ++i) {
        if (Q[i].t == 0) {
            dsu.merge(Q[i].u, Q[i].v, i+1);
            cout << dsu.weight(-1) << '\n';
        } else if (Q[i].t == 1) {
            int k = Q[i].u; 
            cout << dsu.weight(-(k+1)) << '\n';
            if (i == m || Q[i+1].t != 2) {
                while (k--) dsu.undo();
            }
        } else {
            if (Q[i-1].t != 1) dsu.undo();
            cout << dsu.weight(-1) << '\n';
        }
    }
 
    return 0;
}
