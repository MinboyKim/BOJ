#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long Arr[10101], N, t, ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> Arr[i];

    sort(Arr, Arr + N);

    if (N % 2 == 0) {
        for (int i = 0; i < N; i++) {
            ans = max(ans, Arr[i] + Arr[N - 1 - i]);
        }
    } else {
        ans = Arr[N - 1];
        for (int i = 0; i < N; i++) {
            ans = max(ans, Arr[i] + Arr[N - 2 - i]);
        }
    }

    cout << ans << "\n";

    return 0;
}