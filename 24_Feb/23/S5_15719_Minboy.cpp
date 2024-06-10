#include <iostream>

using namespace std;

int N, ans, temp;
int Arr[10'010'111];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (Arr[temp])
            ans = temp;
        else
            Arr[temp] = 1;
    }

    cout << ans << "\n";

    return 0;
}