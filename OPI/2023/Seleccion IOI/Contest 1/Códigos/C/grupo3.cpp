#include<bits/stdc++.h>
using namespace::std;

const int E = 4;
const int N = 100000 + 5;
const int SUML = 2000000 + 5;
const string alphabet = "AGCU";

int id(char c) {
    for(int i = 0; i < 4; i++) if(alphabet[i] == c) return i;
    assert(false);
}

int n;
int m;
int T;
int nodes;
int ans[N];
string s[N];
string Q[N];
int in[SUML];
int out[SUML];
int sorted[N];
int frec[SUML];
int trie[E][SUML];
vector<int> ids[SUML];
vector<int> queries[SUML];

void add_node() {
    for(int i = 0; i < E; i++) trie[i][nodes] = 0;
    frec[nodes] = 0;
    ids[nodes].clear();
    nodes += 1;
}

void insert(string &s, int at) {
    int pos = 0;
    for(int i = 0; i < s.size(); i++) {
        int c = id(s[i]);
        if(trie[c][pos] == 0) {
            trie[c][pos] = nodes;
            add_node();
        }
        pos = trie[c][pos];
        frec[pos] += 1;
    }
    ids[pos].emplace_back(at);
}

void DFS(int u) {
    in[u] = T;
    for(auto x : ids[u]) {
        sorted[T++] = x;
    }
    for(int c = 0; c < E; c++) {
        if(!trie[c][u]) continue;
        DFS(trie[c][u]);
    }
    out[u] = T - 1;
}

void build() {
    nodes = 0;
    add_node();
    for(int i = 0; i < n; i++) {
        insert(s[i], i);
        reverse(s[i].begin(), s[i].end());
    }
    DFS(0);
}

int get_node(string &s) {
    int pos = 0;
    for(int i = 0; i < s.size(); i++) {
        int c = id(s[i]);
        if(trie[c][pos] == 0) return -1;
        pos = trie[c][pos];
    }
    return pos;
}

int query(string &s) {
    int pos = 0;
    for(int i = 0; i < s.size(); i++) {
        int c = id(s[i]);
        if(trie[c][pos] == 0) return 0;
        pos = trie[c][pos];
    }
    return frec[pos];
}

void solve() {
    vector<int> nodes_with_queries;
    for(int i = 0; i < nodes; i++) {
        if(not queries[i].empty()) nodes_with_queries.emplace_back(i);
    }
    for(auto x : nodes_with_queries) {
        nodes = 0;
        add_node();
        int l = in[x], r = out[x];
        for(int j = l; j <= r; j++) {
            insert(s[sorted[j]], sorted[j]);
        }
        for(auto to : queries[x]) {
            ans[to] = query(Q[to]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    build();
    for(int i = 0; i < m; i++) {
        string P;
        cin >> P >> Q[i];
        reverse(Q[i].begin(), Q[i].end());
        int node = get_node(P);
        if(~node) {
            queries[node].emplace_back(i);
        }
    }
    solve();
    for(int i = 0; i < m; i++) printf("%d\n", ans[i]);
    return 0;
}
