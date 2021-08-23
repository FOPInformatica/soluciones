#include<bits/stdc++.h>
using namespace::std;

const int N = 1000000 + 5;

int n;
int m;
int a;
int s;
int c;
int k;
int len1;
int len2;
vector<int> val1;
vector<int> stack1, stack2;

inline int mul(int a, int b, int m){
	return (1ll * a * b) % m;
}

inline int add(int a, int b, int m){
	return (a + b) % m;
}

void push(int x){
	val1[len1 + 1] = x;
	stack1[len1 + 1] = max(stack1[len1], x);
	len1 += 1;
}

void pop(){
	if(len2 == 0){
		while(len1 > 0){
			stack2[len2 + 1] = max(stack2[len2], val1[len1]);
			len2 += 1;
			len1 -= 1;
		}
	}
	len2 -= 1;
}

int Max(){
	return max(stack1[len1], stack2[len2]);
}

int main(){
	scanf("%d %d %d %d %d %d", &a, &s, &c, &n, &m, &k);
	vector<int> v(n);
	val1.assign(n + 1, 0);
	stack1.assign(n + 1, 0);
	stack2.assign(n + 1, 0);
	for(int i = 0; i < n; i++){
		s = add(mul(a, s, m), c, m);
		v[i] = s;
	}
	for(int i = 0; i + 1 < k; i++){
		push(v[i]);
	}
	for(int i = k - 1; i < n; i++){
		push(v[i]);
		if(i - k >= 0) pop();
		printf("%d%c", Max(), " \n"[i + 1 == n]);
	}
	return 0;
}