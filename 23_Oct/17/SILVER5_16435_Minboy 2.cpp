#include <iostream>
#include <algorithm>

int N, L;
int Arr[1111];

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> L;
    for (int i = 0; i < N; i++)
        cin >> Arr[i];
    sort(Arr, Arr + N);

    for (int i = 0; i < N; i++) {
        if (Arr[i] <= L)
            L++;
        else
            break;
    }

    cout << L << "\n";

    return 0;
}