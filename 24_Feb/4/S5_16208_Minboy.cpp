#include <iostream>

using namespace std;

unsigned long long n, ans, sum;
int Arr[505'050];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> Arr[i];
        sum += Arr[i];
    }

    for (int i = 0; i < n; i++) {
        ans += Arr[i] * (sum -= Arr[i]);
    }

    cout << ans << "\n";

    return 0;
}