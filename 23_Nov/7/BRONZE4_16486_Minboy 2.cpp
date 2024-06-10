#include <iostream>

using namespace std;

double d1, d2, PI = 3.141592;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> d1 >> d2;
    cout << fixed;
    cout.precision(6);
    cout << 2 * PI * d2 + 2 * d1 << "\n";

    return 0;
}