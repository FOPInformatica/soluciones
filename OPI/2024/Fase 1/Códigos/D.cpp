#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin>>a[i];
    reverse(a.begin(), a.end());
    int k = 32 - __builtin_clz(n);
    vector<vector<int>> b(2, vector<int>(n+1));
    cout << 2 * k * n << '\n';
    for (int d=0; d<k; ++d) {
        int t[2];
        memset(t, 0, sizeof t);
        for (int j=n-1; j>=0; --j) {
            if (a[j] & (1<<d)) {
                b[1][t[1]++] = a[j];
                cout << "1 3" << '\n';
            } else {
                b[0][t[0]++] = a[j]; 
                cout << "1 2" << '\n';
            }
        }
        int l=0;
        for (int j=1; j>=0; --j)
            for (int i=t[j]-1; i>=0; --i) {
                a[l++] = b[j][i];
                if (j == 1) cout << "3 1" << '\n';
                else cout << "2 1" << '\n';
            }
    }
    return 0;
}
