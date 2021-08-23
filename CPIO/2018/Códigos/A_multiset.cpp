#include<bits/stdc++.h>
using namespace::std;

int n;
int m;
int a;
int s;
int c;
int k;

inline int mul(int a, int b, int m){
	return (1ll * a * b) % m;
}

inline int add(int a, int b, int m){
	return (a + b) % m;
}

int main(){
	scanf("%d %d %d %d %d %d", &a, &s, &c, &n, &m, &k);
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		s = add(mul(a, s, m), c, m); // (a * s + c) % m
		v[i] = s;
	}
	multiset<int> S;
	for(int i = 0; i + 1 < k; i++) S.emplace(v[i]);
	for(int i = k - 1; i < n; i++){
		S.emplace(v[i]);
		if(i - k >= 0) S.erase(S.find(v[i - k]));
		printf("%d%c", *S.rbegin(), " \n"[i + 1 == n]);
	}
	return 0;
}