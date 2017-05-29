#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> pos(n, -1);
    for (int &x : v)
        cin >> x;
    pos[0] = 0;

    int i;
    for (i = 0; i < v.size(); ++i) {
        int sum = v[i];
        for (int j = i + 1; j < v.size(); ++j) {
            sum += v[j];
            if (sum % n == 0) {
                cout << j - i + 1 << endl;
                for (int k = i; k <= j; ++k) {
                    cout << v[k] << ' ';
                }
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}
