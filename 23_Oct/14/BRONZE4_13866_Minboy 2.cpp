#include <iostream>
#include <algorithm>

using namespace std;

int Arr[4];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < 4; i++)
        cin >> Arr[i];

    sort(Arr, Arr + 4);

    cout << abs(Arr[0] + Arr[3] - Arr[1] - Arr[2]) << "\n";

    return 0;
}