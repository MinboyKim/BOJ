#include <iostream>

using namespace std;

int N, K, l, r, ans;
int Arr[202'020];
int cnt[101'010];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> Arr[i];

    while (r < N) {
        if (cnt[Arr[r]] < K) {
            cnt[Arr[r]]++;
            r++;
        } else {
            cnt[Arr[l]]--;
            l++;
        }
        ans = max(ans, r - l);
    }

    cout << ans << "\n";

    return 0;
}