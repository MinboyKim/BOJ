#include <iostream>

using namespace std;

int N;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++)
            cout << "*";
        for (int j = 0; j < 2 * (N - i); j++)
            cout << " ";
        for (int j = 0; j < i; j++)
            cout << "*";
        cout << "\n";
    }
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++)
            cout << "*";
        for (int j = 0; j < 2 * N - (2 * i); j++)
            cout << " ";
        for (int j = 0; j < i; j++)
            cout << "*";
        cout << "\n";
    }

    return 0;
}