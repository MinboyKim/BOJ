#include <iostream>

using namespace std;

int A, B, C, D, E;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> A >> B >> C >> D >> E;

    int temp = 1;
    while (true) {
        int cnt = 0;
        if (temp % A == 0) cnt++;
        if (temp % B == 0) cnt++;
        if (temp % C == 0) cnt++;
        if (temp % D == 0) cnt++;
        if (temp % E == 0) cnt++;
        if (cnt >= 3) {
            cout << temp << "\n";
            return 0;
        }
        temp++;
    }

    return 0;
}