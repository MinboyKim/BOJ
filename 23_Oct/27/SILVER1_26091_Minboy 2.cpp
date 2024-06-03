#include <iostream>
#include <algorithm>

using namespace std;

int N, M, ans;
int Arr[100'010];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> Arr[i];
    if (N == 1) {
        cout << 0 << "\n";
        return 0;
    }
    sort(Arr, Arr + N);
    int l = 0, r = N - 1;
    while (l < r) {
        if (Arr[l] + Arr[r] >= M) {
            ans++;
            l++;
            r--;
        } else {
            l++;
        }
    }

    cout << ans << "\n";

    return 0;
}