#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;
int Arr[101'010];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> Arr[i];

    sort(Arr, Arr + n);

    for (int i = n - 2; i >= 0; i--) {
        ans += Arr[n - 1] + Arr[i];
    }

    cout << ans << "\n";

    return 0;
}