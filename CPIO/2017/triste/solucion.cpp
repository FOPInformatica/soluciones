#include <iostream>

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    for (char &c : s)
        c = c == 'F' ? 1 : 0;
    int moves = 0;
    int i;
    for (i = 0; i + k <= s.size(); ++i) {
        if (not s[i]) {
            for (int j = i; j < i + k; ++j)
                s[j] = not s[j];
            ++moves;
        }
    }
    bool valid = true;
    for ( ; valid && i < s.size(); ++i) {
        if (not s[i])
            valid = false;
    }
    if (valid)
        cout << moves;
    else
        cout << -1;
    cout << endl;
}
