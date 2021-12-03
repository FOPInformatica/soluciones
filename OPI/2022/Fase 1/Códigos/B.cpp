#include<bits/stdc++.h>
using namespace::std;

bool check(vector<bool> &v){
	if(v.size() < 9) return true;
	for(int i = 1; i <= 9; i++){
		if(not v[v.size() - i]) return true;
	}
	return false;
}

int main(){
	vector<bool> valid;
	valid.emplace_back(true);
	int at = 1;
	while(check(valid)){
		bool cur = false;
		if(at >= 9 and valid[at - 9]) cur = true;
		if(at >= 17 and valid[at - 17]) cur = true;
		if(at >= 25 and valid[at - 25]) cur = true;
		valid.emplace_back(cur);
		at++;
	}
	for(int i = valid.size() - 1; i >= 0; i--){
		if(not valid[i]){
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
