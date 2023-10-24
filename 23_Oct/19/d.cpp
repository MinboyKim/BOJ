#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string n;
    cin >> n;
    if (n.size() < 3) {
        return 0;
    }
    long long ans = (n[0] - '0' - 1) * pow(10, n.size() - 2);
    for (int i = 1; i < (n.size() + 1) / 2; i++) {
        long long cur = n[i] - '0' + 1;
        ans += cur * pow(10, n.size() - 2 * i);
    }
    cout << ans;

    return 0;
}