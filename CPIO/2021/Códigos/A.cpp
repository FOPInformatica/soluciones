#include<bits/stdc++.h>
using namespace::std;

const int N = 4000 + 5;

int n;
int m;
int a[N];
int b[N];
int A[N][N];
int B[N][N];
bool vis[N][N];
int memo[N][N];

int getInversions(){
	int ans = 0;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			ans += (a[j] > a[i]);
		}
	}
	for(int i = 1; i < m; i++){
		for(int j = 0; j < i; j++){
			ans += (b[j] > b[i]);
		}
	}
	return ans;
}

int solve(){
	for(int i = n - 1; i >= 0; i--){
		for(int j = m - 1; j >= 0; j--){
			A[i][j] = A[i][j + 1] + (a[i] > b[j]);
			B[i][j] = B[i + 1][j] + (b[j] > a[i]);
			memo[i][j] = max(memo[i + 1][j] + A[i][j], memo[i][j + 1] + B[i][j]);
		}
	}
	return memo[0][0];
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	scanf("%d", &m);
	for(int i = 0; i < m; i++) scanf("%d", b + i);
	printf("%d\n", solve() + getInversions());
	return 0;
}