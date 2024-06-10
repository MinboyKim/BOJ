#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
int Arr[111];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> Arr[i];

    sort(Arr, Arr + N);

    int temp = Arr[0];
    for (int i = 1; i < N; i++) {
        ans += temp * Arr[i];
        temp += Arr[i];
    }

    cout << ans << "\n";

    return 0;
}