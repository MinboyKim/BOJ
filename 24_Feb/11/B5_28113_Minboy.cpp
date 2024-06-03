#include <iostream>

using namespace std;

int N, A, B;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> A >> B;

    if (A == B) {
        cout << "Anything\n";
        return 0;
    }

    cout << (B < A ? "Subway\n" : "Bus\n");

    return 0;
}