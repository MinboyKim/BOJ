#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int N, ans, ans_index;
pii Arr[101'010];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> Arr[i].first >> Arr[i].second;

    for (int i = 1; i <= 5; i++) {
        int j = 0;
        while (j < N) {
            int cnt = 0;
            while (Arr[j].first == i || Arr[j].second == i) {
                cnt++;
                j++;
            }
            if (ans < cnt) {
                ans = cnt;
                ans_index = i;
            }
            j++;
        }
    }

    cout << ans << " " << ans_index << "\n";

    return 0;
}