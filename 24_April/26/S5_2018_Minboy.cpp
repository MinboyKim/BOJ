#include <iostream>

using namespace std;

int N, ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int temp = 0;
        for (int j = i; j <= N; j++) {
            temp += j;
            if (temp == N) {
                ans++;
                break;
            }
            if (temp > N) break;
        }
    }

    cout << ans << "\n";

    return 0;
}