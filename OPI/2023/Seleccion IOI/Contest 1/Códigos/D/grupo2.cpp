#include<bits/stdc++.h>
using namespace::std;

const int N = 500 + 5;
const double PI = acos(-1);
const double EPS = 1e-4;

int n;
int m;
int x[N];
int y[N];
pair<double, int> angles[4 * N];

bool can(double R, double &X, double &Y) {
    for(int i = 1; i <= n; i++) {
        int at = 0;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            double d = hypot(x[i] - x[j], y[i] - y[j]);
            if(d > 2 * R) continue;
            double angle1 = atan2(y[j] - y[i], x[j] - x[i]);
            double angle2 = acos(d / (2 * R));
            angles[at++] = make_pair(angle1 - angle2, 1);
            angles[at++] = make_pair(angle1 + angle2, -1);
            angles[at++] = make_pair(angle1 - angle2 + 2 * PI, 1);
            angles[at++] = make_pair(angle1 + angle2 + 2 * PI, -1);
        }
        sort(angles, angles + at);
        int cnt = 1;
        for(int j = 0; j < at; j++) {
            cnt += angles[j].second;
            if(cnt >= m) {
                X = x[i] + R * cos(angles[j].first);
                Y = y[i] + R * sin(angles[j].first);
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d %d", x + i, y + i);
    double lo = 0, hi = 2e4;
    double X, Y;
    for(int i = 0; i < 45; i++) {
        double mi = (lo + hi) / 2.0;
        if(can(mi, X, Y)) hi = mi;
        else lo = mi;
    }
    printf("%.10lf\n", lo);
    printf("%.10lf %.10lf\n", X, Y);
    return 0;
}
