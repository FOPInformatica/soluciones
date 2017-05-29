#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        G[x - 1].push_back(i);
    }
    vector<vector<int>> DP(n, vector<int>(2));
    for (int u = n - 1; u >= 0; --u) {
        int taken[] = {0, 0};
        for (int v : G[u]) {
            taken[0] += DP[v][0];
            taken[1] += DP[v][1];
        }
        DP[u][0] = 1 + taken[1];
        DP[u][1] = min(1 + taken[1], taken[0]);
    }
    cout << DP[0][1] << endl;
}
