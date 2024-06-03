#include <iostream>

using namespace std;

int H, W, ans;
int Arr[555];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> H >> W;

    for (int i = 0; i < W; i++)
        cin >> Arr[i];

    for (int i = 0; i < W; i++) {
        int lm = 0, rm = 0;
        for (int j = 0; j < i; j++)
            lm = max(lm, Arr[j]);
        for (int j = i + 1; j < W; j++)
            rm = max(rm, Arr[j]);

        if (!lm || !rm) continue;

        ans += (min(lm, rm) - Arr[i] > 0 ? min(lm, rm) - Arr[i] : 0);
    }

    cout << ans << "\n";

    return 0;
}