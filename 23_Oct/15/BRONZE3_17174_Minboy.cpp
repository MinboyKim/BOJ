#include <iostream>

using namespace std;

int N, M, ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    ans += N;
    while (N /= M)
        ans += N;

    cout << ans << "\n";

    return 0;
}