#include<bits/stdc++.h>
using namespace::std;

const int N = 50 + 5;
const int MAX = 100 + 5;
const int inf = 1e9 + 10;

int n;
int l[N];
int f[N];
bool vis[N][MAX][MAX];
int memo[N][MAX][MAX];

int DP(int pos, int llenura, int felicidad){
    if(pos == n) return felicidad == 100 ? 0 : -inf;
    if(vis[pos][llenura][felicidad]) return memo[pos][llenura][felicidad];
    int ans = DP(pos + 1, llenura, felicidad);
    if(llenura + l[pos] <= 100) ans = max(ans, 1 + DP(pos + 1, llenura + l[pos], min(100, felicidad + f[pos])));
    vis[pos][llenura][felicidad] = true;
    return memo[pos][llenura][felicidad] = ans;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", l + i, f + i);
    printf("%d\n", DP(0, 0, 0));
    return 0;
}