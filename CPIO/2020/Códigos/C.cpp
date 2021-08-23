#include<bits/stdc++.h>
using namespace::std;

const int N = 1000 + 5;
const int K = 100 + 5;

int n;
int m;
int k;
int cap[N];
int carga[N][K];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) cap[i] = m;
    scanf("%d", &k);
    int cnt = 0;
    for(int i = 1; i <= k; i++){
        int id, mem;
        scanf("%d %d", &id, &mem);
        int choice = -1;
        for(int j = 1; j <= n; j++){
            if(cap[j] < mem) continue;
            if(choice == -1){
                choice = j;
                continue;
            }
            if(carga[j][id] < carga[choice][id]){
                choice = j;
                continue;
            }
            if(carga[j][id] == carga[choice][id] and cap[j] > cap[choice]){
                choice = j;
                continue;
            }
        }
        if(choice == -1) continue;
        cap[choice] -= mem;
        carga[choice][id] += 1;
        cnt += 1;
    }
    printf("%d\n", cnt);
    for(int i = 1; i <= n; i++) printf("%d%c", m - cap[i], " \n"[i == n]);
    return 0;
}