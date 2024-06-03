#include <iostream>

using namespace std;

int a, b;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> a >> b;

    if (a == 2 && b == 18) {
        cout << "Special\n";
        return 0;
    }

    if ((a == 2 && b < 18) || (a < 2))
        cout << "Before\n";
    else
        cout << "After\n";

    return 0;
}