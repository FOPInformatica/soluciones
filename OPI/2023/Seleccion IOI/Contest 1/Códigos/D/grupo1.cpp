#include<bits/stdc++.h>
using namespace::std;

const int N = 100 + 5;
const long double EPS = 1e-4;

int n;
int m;
int x[N];
int y[N];

void rotate(pair<int, int> &P) {
    P.second *= -1;
    swap(P.first, P.second);
}

int cross(pair<int, int> A, pair<int, int> B) {
    return A.first * B.second - A.second * B.first;
}

void solve() {
    long double best_X = 0, best_Y = 0;
    long double best = DBL_MAX;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            long double diam_R = hypotl(x[i] - x[j], y[i] - y[j]) / 2.0;
            long double diam_X = (x[i] + x[j]) / 2.0;
            long double diam_Y = (y[i] + y[j]) / 2.0;
            int cur_cnt = 0;
            for(int p = 1; p <= n; p++) {
                if(hypotl(x[p] - diam_X, y[p] - diam_Y) <= diam_R + EPS) cur_cnt += 1;
            }
            if(cur_cnt >= m) {
                if(diam_R < best) {
                    best = diam_R;
                    best_X = diam_X;
                    best_Y = diam_Y;
                }
            }
            for(int k = j + 1; k <= n; k++) {
                pair<int, int> ij = make_pair(x[j] - x[i], y[j] - y[i]);
                pair<int, int> jk = make_pair(x[k] - x[j], y[k] - y[j]);
                if(cross(ij, jk) == 0) continue;
                rotate(ij); rotate(jk);
                int A = ij.first, B = -jk.first;
                int C = ij.second, D = -jk.second;
                long double X0 = (x[k] - x[i]) / 2.0, X1 = (y[k] - y[i]) / 2.0;
                long double t = (X0 * D - B * X1) / (A * D - B * C);
                long double t2 = (-X0 * C + A * X1) / (A * D - B * C);
                long double cur_X = (x[i] + x[j]) / 2.0 + t * ij.first;
                long double cur_Y = (y[i] + y[j]) / 2.0 + t * ij.second;
                long double cur_X2 = (x[j] + x[k]) / 2.0 + t2 * jk.first;
                long double cur_Y2 = (y[j] + y[k]) / 2.0 + t2 * jk.second;
                long double R = hypotl(cur_X - x[i], cur_Y - y[i]);
                int cnt = 0;
                for(int p = 1; p <= n; p++) {
                    if(hypotl(x[p] - cur_X, y[p] - cur_Y) <= R + EPS) cnt += 1;
                }
                if(cnt < m) continue;
                if(R < best) {
                    best = R;
                    best_X = cur_X;
                    best_Y = cur_Y;
                }
            }
        }
    }
    printf("%.10Lf\n", best);
    printf("%.10Lf %.10Lf\n", best_X, best_Y);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d %d", x + i, y + i);
    solve();
    return 0;
}
