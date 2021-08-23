#include<bits/stdc++.h>
using namespace::std;

const int N = 100000 + 5;

int n;
char s[N];

int main(){
    scanf("%d", &n);
    scanf("%s", s);
    bool cafe = false;
    for(int i = 0; i + 1 < n; i++) cafe |= s[i] == 'C';
    if(cafe) puts(s[n - 1] == 'C' ? "C" : "L");
    else puts(s[n - 1] == 'C' ? "D" : "L");
    return 0;
}