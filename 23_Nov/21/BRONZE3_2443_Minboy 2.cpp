#include <iostream>

using namespace std;

int N;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++)
            cout << " ";
        for (int j = 1; j <= 2 * N - (2 * i - 1); j++)
            cout << "*";
        cout << "\n";
    }

    return 0;
}