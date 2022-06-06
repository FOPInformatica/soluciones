#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

bool is_candidate[10];

int OK = -2;
double mat[11][11];

int attempt(int x, int y, int z) {
  cout << "? " << x << y << z << endl;
  fflush(stdout);
  char c;
  cin >> c;
  if (c >= '0' && c <= '9')
    return c - '0';
  cin >> c;
  return OK;
}

void permuta(int x, int y, int z) {
  if (attempt(x, y, z) == OK)
    return;
  if (attempt(x, z, y) == OK)
    return;
  if (attempt(y, x, z) == OK)
    return;
  if (attempt(y, z, x) == OK)
    return;
  if (attempt(z, x, y) == OK)
    return;
  if (attempt(z, y, x) == OK)
    return;
}

void print_matrix() {
  return;
  cout << "------------------" << endl;
    for (int i = 0 ; i < 10; i++)
    cout << i << " ";
  cout << "sum" << endl;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 11; j++)
      cout << mat[i][j] << " ";
    cout << endl;
  }
  cout << "------------------" << endl;
}

void solve() {
  /*
  for (int i = 0; i < 10; i++) {
    for (int j = i + 1; j < 10; j++) {
      for (int k = j + 1; k < 10; k++) {
        int x = attempt(i, j, k);
        if (x == OK)
          return;
        if (x == 3) {
          permuta(i, j, k);
          return;
        }
      }
    }
  }
  */
  memset(mat, 0, sizeof mat);
  for (int a = 0; a < 10; a++) {
    int b = (a + 1) % 10;
    int c = (a + 2) % 10;
    mat[a][a] = 1;
    mat[a][b] = 1;
    mat[a][c] = 1;
    mat[a][10] = attempt(a, b, c);
    if (mat[a][10] == OK)
      return;
  }
  print_matrix();

  for (int r = 0; r < 10; r++) {
    double s = mat[r][r];
    for (int c = r; c < 11; c++)
      mat[r][c] /= s;

    for (int r2 = 0; r2 < 10; r2++) if (r2 != r) {
      double factor = mat[r2][r];
      for (int c = r; c < 11; c++)
        mat[r2][c] -= factor * mat[r][c];
    }
   // cout << "processed " << r << endl;
    print_matrix();
  }

  vector<int> candidates;
  for (int i = 0; i < 10; i++) if (mat[i][10] > 0.5)
    candidates.push_back(i);

  if (candidates.size() != 3) {
    *((int *)0) = 12;
  }

  print_matrix();

  permuta(candidates[0], candidates[1], candidates[2]);
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}
