#include <iostream>

using namespace std;

int N, M, I, J, K;
int Arr[111];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> I >> J >> K;
        for (int j = I - 1; j < J; j++)
            Arr[j] = K;
    }

    for (int i = 0; i < N; i++)
        cout << Arr[i] << " ";

    return 0;
}