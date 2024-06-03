#include <iostream>
#include <algorithm>

using namespace std;

int N;
double Arr[10'010'101];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> Arr[i];

    sort(Arr, Arr + N);

    cout << fixed;
    cout.precision(3);
    for (int i = 0; i < 7; i++)
        cout << Arr[i] << "\n";

    return 0;
}