#include<bits/stdc++.h>
using namespace::std;

const int N = 100000 + 5;

int n;
int memo[N][2];
vector<int> G[N];

int main(){
	scanf("%d", &n);
	for(int i = 2, p; i <= n; i++){
		scanf("%d", &p);
		G[p].emplace_back(i);
	}
    for(int i = n; i >= 1; i--){
        for(int usada = 0; usada < 2; usada++){
            int ans = usada;
            for(int v : G[i]){
                if(usada) ans += min(memo[v][0], memo[v][1]);
                else ans += memo[v][1];
            }
            memo[i][usada] = ans;
        }
    }
	printf("%d\n", min(memo[1][0], memo[1][1]));
	return 0;
}