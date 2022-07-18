#include<bits/stdc++.h>
using namespace::std;

const int N = 5000 + 5;
const int MAX = 1000000 + 5;
const long long inf = 1e18;

int n;
int a[N];
int b[N];
bool vis[MAX];
long long memo[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= n; i++) scanf("%d", b + i);
	for(int i = 1; i <= n; i++){
		int j = i;
		int OR = 0;
		memo[i] = inf;
		while(j >= 1 and !vis[a[j]]){
			vis[a[j]] = true;
			OR |= b[j];
			memo[i] = min(memo[i], memo[j - 1] + OR);
			j--;
		}
		for(int k = j + 1; k <= i; k++) vis[a[k]] = false;
	}
	printf("%lld\n", memo[n]);
	return 0;
}

