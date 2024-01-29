#include <iostream>

using namespace std;

long long ans, a;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (true) {
        cin >> a;
        if (a == -1) break;
        ans += a;
    }

    cout << ans << "\n";

    return 0;
}