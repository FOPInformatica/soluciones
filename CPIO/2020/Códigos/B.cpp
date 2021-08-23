#include<bits/stdc++.h>
using namespace::std;

const int N = 500 + 5;
const int M = 900000 + 5;

int n;
int m;
char a[N];
char b[M];

int o(char c){
    if('A' <= c and c <= 'Z') return c - 'A';
    if('a' <= c and c <= 'z') return c - 'a' + 26;
    return c - '0' + 52;
}

int solve(vector<int> &want){
    if(n > m) return 0;
    vector<int> have(62, 0);
    for(int i = 0; i + 1 < n; i++){
        have[o(b[i])] += 1;
    }
    int res = 0;
    for(int i = n - 1; i < m; i++){
        have[o(b[i])] += 1;
        if(i >= n) have[o(b[i - n])] -= 1;
        if(have == want) res += 1;
    }
    return res;
}

int main(){
    scanf("%s", a);
    scanf("%s", b);
    n = strlen(a); m = strlen(b);
    vector<int> want(62, 0);
    for(int i = 0; a[i]; i++) want[o(a[i])] += 1;
    printf("%d\n", solve(want));
    return 0;
}