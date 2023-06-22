#include<bits/stdc++.h>
using namespace::std;

const int inf = 1e9 + 10;

int n;
int m;

bool match(int D, vector<int> &L, vector<int> &R) {
    int at = 0;
    for(auto x : L) {
        while(at < R.size() and R[at] < x - D) at += 1;
        if(at == R.size() or R[at] > x + D) return false;
        at += 1;
    }
    return true;
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
    int lo = 0, hi = 1e9;
    while(lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if(not match(mi, L, R)) lo = mi + 1;
        else hi = mi;
    }
    printf("%d\n", lo);
    return 0;
}
