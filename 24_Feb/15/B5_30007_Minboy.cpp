#include <iostream>

using namespace std;

int W, A, B, X, N;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    while (N--) {
        cin >> A >> B >> X;
        cout << A * (X - 1) + B << "\n";
    }

    return 0;
}