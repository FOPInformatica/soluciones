#include <iostream>
#include <cstdio>
using namespace std;
#define N 1000007

char s[N];

int sigue[N][2];

int main() {
  int n;
  scanf("%d %s", &n, s);
  sigue[n - 1][0] = sigue[n - 1][1] = n;
  long long res = 0;

  for (int i = n - 2; i >= 0; i--) {
    sigue[i][0] = sigue[i + 1][0];
    sigue[i][1] = sigue[i + 1][1];

    sigue[i][s[i + 1] == 'o' ? 0 : 1] = i + 1;

    if (s[i] == 'o')
      res += n - sigue[i][1];
    else
      res += n - sigue[i][0];
  }
  cout << res << endl;


}
