#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int T, N, ans, a, b;
pii Arr[101'010];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;

    while (T--) {
        ans = 1;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a >> b;
            Arr[i] = {a, b};
        }
        sort(Arr, Arr + N);
        int top = Arr[0].second;
        for (int i = 1; i < N; i++) {
            if (Arr[i].second < top) {
                ans++;
                top = Arr[i].second;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}