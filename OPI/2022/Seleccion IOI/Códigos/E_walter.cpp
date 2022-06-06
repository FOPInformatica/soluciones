#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <set>
using namespace std;

#define V 100002
vector<int> E[V];
pair<int, int> Q[V];
uint64_t MASKS[V], DP[V];

int main() {
  memset(MASKS, 0, sizeof MASKS);

  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);

  for (int i = 0; i < m; i++) {
    int a, b; scanf("%d %d", &a, &b);
    E[a].push_back(b);
  }

  for (int i = 0; i < q; i++) {
    int a, b; scanf("%d %d", &a, &b);
    Q[i] = make_pair(a, b);
  }

  for (int i = 0; i < q; i += 64) {
    set<int> ends;
    for (int j = 0; j < 64 && i + j < q; j++)
      ends.insert(Q[i + j].second);

    uint64_t mask = 1; 
    for (int end : ends) {
      MASKS[end] = mask;
      mask <<= 1; 
    }

    memset(DP, 0, sizeof DP);
    for (int u = n; u >= 1; u--) {
      DP[u] |= MASKS[u];
      for (int v : E[u])
        DP[u] |= DP[v];
    }

    for (int j = 0; j < 64 && i + j < q; j++) {
      int a = Q[i + j].first, b = Q[i + j].second;
      if (DP[a] & MASKS[b])
        printf("Si\n");
      else
        printf("No\n");
    }

    for (int end : ends)
      MASKS[end] = 0;
  }
}
