#include <iostream>

using namespace std;

int N, M, ans, j, l, r, a;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> j;
    l = 1;
    r = M;
    int temp = 0;
    while (j--) {
        cin >> a;
        if (l <= a && a <= r) continue;
        if (a < l) {
            temp = l - a;
            ans += temp;
            l -= temp;
            r -= temp;
        } else {
            temp = a - r;
            ans += temp;
            r += temp;
            l += temp;
        }
    }

    cout << ans << "\n";

    return 0;
}