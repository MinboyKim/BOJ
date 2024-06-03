#include <iostream>

using namespace std;

int A, B, ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> A >> B;

    A -= 2;
    B -= 1;

    cout << 2 * min(A, B) + 3 << "\n";

    return 0;
}