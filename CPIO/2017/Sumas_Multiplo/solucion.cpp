#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int sum = 0;
    vector<int> v(n);
    vector<int> pos(n, -1);
    for (int &x : v)
        cin >> x;
    pos[0] = 0;

    int i;
    for (i = 0; i < v.size(); ++i) {
        sum = (sum + v[i]) % n;
        if (pos[sum] != -1)
            break;
        pos[sum] = i + 1;
    }

    cout << (i - pos[sum] + 1) << endl;
    for (int j = pos[sum]; j <= i; ++j)
        cout << v[j] << ' ';
    cout << endl;
    return 0;
}
