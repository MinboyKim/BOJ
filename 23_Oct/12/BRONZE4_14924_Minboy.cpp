#include <iostream>

using namespace std;

int S, T, D;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> S >> T >> D;

    cout << D / (S * 2) * T << "\n";

    return 0;
}