#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define N 705
typedef long long ll;

int mod = 1e9 + 7;

ll DP[N][N];
ll C[N][N];

inline ll fix(ll x) {
    return (x % mod + mod) % mod;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < N; i++)
    for (int j = 0; j <= i; j++) {
        if (i == 0 || j == 0) C[i][j] = 1;
        else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    DP[0][0] = 1;
    for (int h = 1; h <= n; h++) {
	DP[0][h] = 1;
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
        res += (DP[n][h] + mod - DP[n][h - 1]) * (h - 1);
    }
    cout << fix(res) << endl;
    return 0;
}
