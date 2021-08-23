#include<bits/stdc++.h>
using namespace::std;

const int N = 50 + 5;
const int MAX = 100 + 5;
const int inf = 1e9 + 10;

int n;
int l[N];
int f[N];
int maximo[2][MAX][MAX];

void backtracking(int id, int pos, int len, int llenura, int felicidad, int cnt, int start){
    if(pos == len){
        int cur_felicidad = min(100, felicidad);
        maximo[id][llenura][cur_felicidad] = max(maximo[id][llenura][cur_felicidad], cnt);
        return;
    }
    if(llenura + l[pos + start] <= 100) backtracking(id, pos + 1, len, llenura + l[pos + start], felicidad + f[pos + start], cnt + 1, start);
    backtracking(id, pos + 1, len, llenura, felicidad, cnt, start);
}

void get_subsets(int id, int len, int start){
    for(int i = 0; i < MAX; i++) for(int j = 0; j < MAX; j++) maximo[id][i][j] = -inf;
    backtracking(id, 0, len, 0, 0, 0, start);
    if(id){
        for(int i = 1; i <= 100; i++){
            for(int j = 0; j <= 100; j++){
                maximo[id][i][j] = max(maximo[id][i][j], maximo[id][i - 1][j]);
            }
            for(int j = 99; j >= 0; j--){
                maximo[id][i][j] = max(maximo[id][i][j], maximo[id][i][j + 1]);
            }
        }
    }
}

int solve(){
    int res = 0;
    for(int llenura1 = 0; llenura1 <= 100; llenura1++){
        for(int llenura2 = 0; llenura2 + llenura1 <= 100; llenura2++){
            for(int felicidad1 = 0; felicidad1 <= 100; felicidad1++){
                int felicidad2 = 100 - felicidad1;
                res = max(res, maximo[0][llenura1][felicidad1] + maximo[1][llenura2][felicidad2]);
            }
        }
    }
    return res;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", l + i, f + i);
    }
    int len1 = n / 2;
    int len2 = n - len1;
    for(int i = 0; i < 2; i++) get_subsets(i, i == 0 ? len1 : len2, i * len1);
    printf("%d\n", solve());
    return 0;
}