#include<bits/stdc++.h>
using namespace::std;

const int N = 100 + 5;

int n;
int m;
string s[N];

int solve(string &P, string &Q) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(s[i].size() < max(P.size(), Q.size())) continue;
        if(s[i].substr(0, P.size()) != P) continue;
        if(s[i].substr(s[i].size() - Q.size(), Q.size()) != Q) continue;
        res += 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < m; i++) {
        string P, Q;
        cin >> P >> Q;
        cout << solve(P, Q) << '\n';
    }
    return 0;
}
