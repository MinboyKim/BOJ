#include <iostream>

using namespace std;

int A[33], B[33], D, K;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> D >> K;
    A[1] = 1;
    A[2] = 0;
    B[1] = 0;
    B[2] = 1;
    for (int i = 3; i <= D; i++) {
        A[i] = A[i - 2] + A[i - 1];
        B[i] = B[i - 2] + B[i - 1];
    }

    for (int i = 1; i <= K; i++) {
        int temp = K - (A[D] * i);
        if (temp % B[D] == 0) {
            cout << i << "\n" << temp / B[D] << "\n";
            return 0;
        }
    }

    return 0;
}