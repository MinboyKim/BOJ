#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int N;
int Arr[20'202];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> Arr[i];

    sort(Arr, Arr + N);

    if (N % 2 == 0)
        cout << Arr[N / 2 - 1];
    else
        cout << Arr[N / 2];

    return 0;
}