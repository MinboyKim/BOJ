#include <iostream>

using namespace std;

int N, T;
unsigned long long Arr[111];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    Arr[1] = 1;
    Arr[2] = 1;
    Arr[3] = 1;
    Arr[4] = 2;
    Arr[5] = 2;
    Arr[6] = 3;
    Arr[7] = 4;
    Arr[8] = 5;
    Arr[9] = 7;
    Arr[10] = 9;

    for (int i = 11; i <= 100; i++)
        Arr[i] = Arr[i - 3] + Arr[i - 2];

    cin >> T;
    while (T--) {
        cin >> N;
        cout << Arr[N] << "\n";
    }

    return 0;
}