#include<bits/stdc++.h>
using namespace::std;

const int N = 5000 + 5;
const int B = 311;
const int MOD = 1e9 + 7;
const int MAX = 100000 + 5;

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(long long a, long long b) {
    return a * b % MOD;
}

int pow_mod(int a, int b) {
    int r = 1;
    while(b) {
        if(b & 1) r = mul(r, a);
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

int pot[MAX];
int poti[MAX];

struct Hash {
    vector<int> prefix;
    
    void build(string &s) {
        prefix = vector<int>(s.size() + 1, 0);
        for(int i = 1; i <= s.size(); i++) {
            prefix[i] = add(prefix[i - 1], mul(s[i - 1], pot[i]));
        }
    }

    int query(int i, int len) {
        // [i, i + len) 0-indexed
        return mul(poti[i + 1], add(prefix[i + len], MOD - prefix[i]));
    }
};

int n;
int m;
Hash H[N];
string s[N];

void init() {
    pot[0] = 1;
    for(int i = 1; i < MAX; i++) pot[i] = mul(B, pot[i - 1]);
    poti[MAX - 1] = pow_mod(pot[MAX - 1], MOD - 2);
    for(int i = MAX - 2; i >= 0; i--) poti[i] = mul(B, poti[i + 1]);
}

void build() {
    for(int i = 0; i < n; i++) H[i].build(s[i]);
}

int get_hash(string &s) {
    int res = 0;
    for(int i = 0; i < s.size(); i++) {
        res = add(res, mul(s[i], pot[i]));
    }
    return res;
}

int solve(string &P, string &Q) {
    int hash_P = get_hash(P), hash_Q = get_hash(Q);
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(s[i].size() < max(P.size(), Q.size())) continue;
        if(H[i].query(0, P.size()) != hash_P) continue;
        if(H[i].query(s[i].size() - Q.size(), Q.size()) != hash_Q) continue;
        res += 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    build();
    for(int i = 0; i < m; i++) {
        string P, Q;
        cin >> P >> Q;
        cout << solve(P, Q) << '\n';
    }
    return 0;
}
