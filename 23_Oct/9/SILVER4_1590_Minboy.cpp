#include <iostream>

using namespace std;

long long N, T, S, I, C, ans = 1'999'999'999;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> T;
    while (N--) {
        cin >> S >> I >> C;
        int l = 1;
        int r = C;
        while (l <= r) {
            int m = (l + r) / 2;
            if (S + I * (m - 1) >= T) {
                ans = min(ans, S + I * (m - 1) - T);
                r = m - 1;
            } else
                l = m + 1;
        }
    }

    cout << (ans == 1'999'999'999 ? -1 : ans) << "\n";

    return 0;
}