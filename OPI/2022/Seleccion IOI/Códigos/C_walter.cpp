#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;
 
 
/*
1 digito:
 x - x = 0
 
2 digitos:
 xy - x * y = x * 10 + y - x * y = x (10 - y) + y
 
 x, y -> xy + b
 x, y, z -> x * y * z + b
 
 
 (x, y, z) -> xyz - x * y * z = b
              x * (100 - y * z) + yz - = b
              x = (b - y * 10 - z) / (100 - y * z) 
 
si hay un 0, x - P(x) = x
si hay varios 1's
 
int calc(b, X, prod) ->
  calc(b, X - ultimo digito, prod / ultimo digito)
  ...
  calc(b, 0, 1)
 
b = 0
X tiene un 0
b = 1
x - P(x) = 1 -> x * 10 + y - x = 1 
 
int calc(diff, int digitos) {
  if (digitos == 0)
    return diff == 0;
 
  for (int i : 1 -> 9)
    
}
*/
 
uint64_t n, b;
int digits[20];
int counts[10];
int total = 0;
 
void chequea(int digitos, uint64_t num) {
  for (int i = 0; i < 10; i++)
    counts[i] = 0;
  for (int i = 0; i < digitos; i++)
    counts[digits[i]]++;
  
  uint64_t onum= num;
  do {
    counts[num % 10]--;
    num /= 10;
  } while (num);
  for (int i = 0; i < 10; i++) 
    if (counts[i])
      return;
 
  //cout  << onum << endl;
  total++;
}
 
void recurse(int digitos, int ultimo, uint64_t prod) {
  if (prod + b > n || digitos > 12)
    return;
  if (digitos > 0)
    chequea(digitos, prod + b);
 
  for (int i = ultimo; i >= 1; i--) {
    digits[digitos] = i;
    recurse(digitos + 1, i, prod * i);
  }
}
 
int main() {
  cin >> n >> b;
  memset(digits, 0, sizeof digits);
  // si tiene 0 como digito, entonces x = b
  if (b <= n) {
    bool tiene_cero = false;
    uint64_t x = b;
    do {
      // cout << ">   " << x % 10 << endl;
      tiene_cero = tiene_cero || (x % 10 == 0);
      x /= 10;
    } while(x);
    if (tiene_cero)
      total++;
  }
  recurse(0, 9, 1);
  cout << total << endl;
}
