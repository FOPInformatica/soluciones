#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
int n;
#define N 300005

map<int, vector<int>> intervals;

int op[N], ed[N];

int sum(int bit[], int x) {
  int s = 0;
  for (; x; x -= x & (-x))
    s += bit[x];
  return s;
}

int sumRange(int bit[], int from, int to) {
  return sum(bit, to) - sum(bit, from - 1);
}

void add(int bit[], int x, int val) {
  for (; x <= n; x += x & (-x))
    bit[x] += val;
}

int main() {
  int m;
  scanf("%d %d", &n, &m);
  memset(op, 0, sizeof op);
  memset(ed, 0, sizeof ed);
  long long total = 0;

  for (int i = 0; i < m; i++) {
    int a, b; scanf("%d %d", &a, &b);
    intervals[a].push_back(b);
    add(op, a, 1);
    add(ed, b, 1);
  }

  int quedan = m;
  for (auto kv : intervals) {
    int a = kv.first;
    vector<int> &bs = kv.second;

    quedan -= bs.size();
    for (int b : bs) {
      add(op, a, -1);
      add(ed, b, -1);
    }

    for (int b : bs) {
      total += quedan - sumRange(op, b, n) - sumRange(ed, a + 1, b);
    }
  }
  cout << total << endl;

}
