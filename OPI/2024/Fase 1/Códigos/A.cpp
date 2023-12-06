#include<bits/stdc++.h>
using namespace::std;

const int N = 500000 + 5;
const int L = 41;

int n;
long long a[N];

vector<pair<long long, int>> parse(vector<long long> &v) {
	int l = 0;
	vector<pair<long long, int>> res;
	while(l < v.size()) {
		int r = l;
		while(r < v.size() and v[l] == v[r]) r += 1;
		res.emplace_back(v[l], r - l);
		l = r;
	}
	return res;
}

long long get_crossed(vector<pair<long long, int>> a, vector<pair<long long, int>> b, long long m) {
	int sum_a = 0, sum_b = 0;
	for(auto x : a) sum_a += x.second;
	for(auto x : b) sum_b += x.second;
	long long res = 1ll * sum_a * sum_b;
	int at = b.size() - 1;
	int sum = 0;
	for(auto x : a) {
		if(x.first == 0) continue;
		long long want = m - x.first;
		while(at >= 0 and b[at].first >= want) {
			sum += b[at].second;
			at -= 1;
		}
		res -= 1ll * x.second * sum;
	}
	return res;
}

long long get_pairs(vector<pair<long long, int>> &v, long long m) {
	vector<int> suffix_sum;
	for(int i = 0; i < v.size(); i++) suffix_sum.emplace_back(v[i].second);
	suffix_sum.emplace_back(0);
	for(int i = (int)suffix_sum.size() - 2; i >= 0; i--) suffix_sum[i] += suffix_sum[i + 1];
	long long res = 0;
	int at = (int)v.size() - 1;
	for(int i = 0; i < v.size(); i++) {
		long long want = m - v[i].first;
		while(at >= 0 and v[at].first >= want) at -= 1;
		int to = max(at, i) + 1;
		res += 1ll * v[i].second * suffix_sum[to];
		if((v[i].first << 1) >= m) res += 1ll * v[i].second * (v[i].second - 1) / 2;
	}
	return res;
}

long long get_bits(int b, long long p) {
	vector<long long> ones;
	vector<long long> zeros;
	vector<long long> ones_values;
	vector<long long> zeros_values;
	for(int i = 0; i < n; i++) {
		if(a[i] & p) {
			ones.emplace_back(a[i] % p);
			ones_values.emplace_back(a[i]);
		}
		else {
			zeros.emplace_back(a[i] % p);
			zeros_values.emplace_back(a[i]);
		}
	}
	vector<pair<long long, int>> p_ones = parse(ones), p_zeros = parse(zeros);
	long long res = get_crossed(p_ones, p_zeros, p);
	if(not ones.empty()) res += get_pairs(p_ones, p);
	if(not zeros.empty()) res += get_pairs(p_zeros, p);
	for(int i = 0; i < zeros_values.size(); i++) a[i] = zeros_values[i];
	for(int i = 0; i < ones_values.size(); i++) a[i + zeros_values.size()] = ones_values[i];
	return res;
}

int main(){
	scanf("%d", &n);
	long long X = 0, O = 0;
	for(int i = 0; i < n; i++) {
		scanf("%lld", a + i);
		X ^= a[i] << 1;
		O |= a[i] << 1;
	}
	long long p = 1;
	for(int b = 0; b < L; b++, p <<= 1) {
		long long cnt = get_bits(b, p);
		if(cnt & 1) X ^= p;
		if(cnt) O |= p;
	}
	printf("%lld %lld\n", X, O);
	return 0;
}
