#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define N 705
typedef long long ll;

const ll mod = 1e9 + 7;

ll DP[N][N];
ll C[N][N];

inline ll fix(ll x) {
    return (x % mod + mod) % mod;
}
/*
ll f(int n, int h) {
    if (n == 0) return 1;
    if (h == 0) return 0;
    ll &res = DP[n][h];
    if (res != -1) 
        return res;
    res = 0;
    for (int i = 1; i <= n; i++) {
        res += fix(C[n - 1][i - 1] * fix(f(i - 1, h - 1) * f(n - i, h - 1)));
    }
    res = fix(res);
    return res;
}*/

int main() {
    int n;
    cin >> n;
    //memset(DP, -1, sizeof DP);
    memset(C, 0, sizeof C);

    for (int i = 0; i < N; i++)
    for (int j = 0; j <= i; j++) {
        if (i == 0 || j == 0) C[i][j] = 1;
        else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    for (int h = 0; h <= n; h++) {
        DP[0][h] = 1;
        if (h == 0) {
            for (int nn = 1; nn <= n; nn++)
                DP[nn][h] = 0;
            continue;
        }
        for (int nn = 1; nn <= n; nn++){
            ll &res = DP[nn][h];
            res = 0;
            for (int i = 1; i <= nn; i++)
                res += C[nn - 1][i - 1] * DP[i - 1][h - 1] % mod * DP[nn - i][h - 1] % mod;
            res = res % mod;
        }
    }

    ll res = 0;
    for (int h = 1; h <= n; h++) {
        res += fix(DP[n][h] - DP[n][h - 1]) * (h - 1);
        res = fix(res);
    }
    cout << res << endl;
}
