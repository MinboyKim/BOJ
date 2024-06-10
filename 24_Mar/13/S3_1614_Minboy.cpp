#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull finger, n, ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> finger >> n;

    switch (finger) {
    case 1:
        ans += 8 * n;
        break;
    case 2:
        ans += 1;
        ans += 6 * ((n / 2) + (n % 2));
        ans += 2 * (n / 2);
        break;
    case 3:
        ans += 2;
        ans += 4 * n;
        break;
    case 4:
        ans += 3;
        ans += 2 * ((n / 2) + (n % 2));
        ans += 6 * (n / 2);
        break;
    case 5:
        ans += 4;
        ans += 8 * n;
        break;
    default:
        break;
    }

    cout << ans << "\n";

    return 0;
}