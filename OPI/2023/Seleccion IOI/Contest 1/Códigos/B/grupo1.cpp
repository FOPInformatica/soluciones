#include<bits/stdc++.h>
using namespace::std;

int n;
int m;

int main() {
    scanf("%d %d", &n, &m);
    vector<int> L(n), R(m);
    for(int i = 0; i < n; i++) scanf("%d", &L[i]);
    for(int i = 0; i < m; i++) scanf("%d", &R[i]);
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    int res = 0;
    for(int i = 0; i < n; i++) res = max(res, abs(L[i] - R[i]));
    printf("%d\n", res);
    return 0;
}
