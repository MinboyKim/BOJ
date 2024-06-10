#include <iostream>

using namespace std;

int M, X, Y, ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> M;

    ans = 1;
    for (int i = 0; i < M; i++) {
        cin >> X >> Y;
        if (X == ans)
            ans = Y;
        else if (Y == ans)
            ans = X;
    }

    cout << ans << "\n";

    return 0;
}