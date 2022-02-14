// Author: Paul Luyo
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int MOD = int(1e9) + 7;


// computes all factorials < n
vector<int> computeFactorials(int n) {
	vector<int> factorials(n, 1);
	for (int i = 1; i < n; ++i) {
		 factorials[i] = (i * 1LL * factorials[i-1]) % MOD;
	}
	return factorials;
}


// computes all d(i) for all i < n
vector<int> computeAllNumberOfDivisors(int n) {
	// sieve O(nlogn)
	vector<int> divisors(n, 0);
	for (int i = 1; i < n; ++i) {
		for (int j = i; j < n; j += i) {
			divisors[j] ++;
		}
	}

	return divisors;
}


int subtaskHard(int n, int m) {
	 vector<int> numDivisors = computeAllNumberOfDivisors(n+1); // if task <= 2 -> O(n\sqrt{n}), task = 3 -> O(nlogn)
	 bool isDataConsistent = true;
	 vector<int> data(n+1, -1); // data[i] is the value at position i, initialized with value -1
	 vector<bool> alreadySeen(n+1, false); // alreadySeen[i] = true if i has already been assigned at some position

	 for (int iteration = 0; iteration < m; ++iteration) {
			int pos = -1, value = -1;
			scanf("%d %d", &pos, &value);
			if (value <= 0 || value > n) {
				isDataConsistent = false;
			}
			else {
				if (alreadySeen[value]) {
					isDataConsistent = false; // value has been seen at 2 different positions
				}
				else {
					alreadySeen[value] = true;
					if (numDivisors[pos] != numDivisors[value]) {
						isDataConsistent = false;
					}
					data[pos] = value;
				}
			}
	 }

	 if (!isDataConsistent) {
			return 0;
	 }
	 else {
			// data is consistent and each data[pos] != -1 means that it has been properly filled
			// group numbers by divisors now
			vector<int> sizeByDivisors(n+1,0);
			for (int pos = 1; pos <= n; ++pos) {
					if (data[pos] != -1) {
						continue;
					}
					sizeByDivisors[numDivisors[pos]] ++;
			}
			vector<int> factorials = computeFactorials(n+1);
			int answer = 1;
			for (int divisors = 1; divisors <= n; ++divisors) {
				  int currentSize = sizeByDivisors[divisors];
				  answer = (answer * 1LL * factorials[currentSize]) % MOD;
			}

			return answer;	 
	}
}


int main() {
	 int n, m; 
	 scanf("%d %d", &n, &m);
	 int answer = subtaskHard(n, m);
	 printf("%d", answer);
	 return 0;
}
