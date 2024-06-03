#include <iostream>

using namespace std;

int A, B;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> A >> B;

    cout << min(A / 2, B);

    return 0;
}