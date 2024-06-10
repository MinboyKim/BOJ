#include <iostream>
#include <string>

using namespace std;

int ans, a, b, c, d;

int make_clock(int a, int b, int c, int d) {
    int num = a * 1000 + b * 100 + c * 10 + d;
    int ret = num;

    for (int i = 0; i < 3; i++) {
        num = num % 1000 * 10 + num / 1000;
        ret = min(ret, num);
    }

    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> a >> b >> c >> d;

    int input = make_clock(a, b, c, d);

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 1; k <= 9; k++) {
                for (int l = 1; l <= 9; l++) {
                    int now = make_clock(i, j, k, l);
                    int temp = i * 1000 + j * 100 + k * 10 + l;
                    if (now == temp) ans++;
                    if (temp == input) {
                        cout << ans << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}