#include <bits/stdc++.h>
using namespace std;

const int maxn = 6e5 + 10;
char s[maxn];
int res[maxn / 6][6];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int n = strlen(s);
        queue<int> p;
        vector<int> par(n);
        for (int i=n-1; i>=0; --i) {
            if (s[i] == '2') p.push(i);
            else if (s[i] == '1' && !p.empty()) par[i] = p.front(), p.pop(); 
        }
        int idx[4] = {0};
        for (int i=0; i<n; ++i) {
            if (s[i] == '1') {
                if (par[i]) {
                    if (idx[0] == idx[1]) {
                        res[idx[3]][4] = i; 
                        res[idx[3]++][5] = par[i];
                    } else {
                        res[idx[1]][1] = i;
                        res[idx[1]++][2] = par[i];
                    }
                } else {
                    res[idx[0]++][0] = i;
                }
            } else if (s[i] == '0') {
                res[idx[2]++][3] = i;
            }
        }
        for (int i=0; 6*i<n; ++i) {
            for (int j=0; j<6; ++j) {
                printf("%d%c", res[i][j] + 1, j==5?'\n':' ');
            }
        }
    }
    return 0;
}
