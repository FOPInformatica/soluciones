#include<bits/stdc++.h>
using namespace::std;

const int inf = 1e9 + 10;

int n;
int m;

int solve(vector<int> &L, vector<int> &R) {
    vector<vector<int>> memo(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        memo[i][0] = inf;
        for(int j = 1; j <= m; j++) {
            memo[i][j] = min(memo[i][j - 1], max(abs(L[i - 1] - R[j - 1]), memo[i - 1][j - 1]));
        }
    }
    return *min_element(memo[n].begin(), memo[n].end());
}

int main() {
    scanf("%d %d", &n, &m);
    vector<int> L(n), R(m);
    for(int i = 0; i < n; i++) scanf("%d", &L[i]);
    for(int i = 0; i < m; i++) scanf("%d", &R[i]);
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    if(n > m) {
        swap(n, m);
        swap(L, R);
    }
    printf("%d\n", solve(L, R));
    return 0;
}
