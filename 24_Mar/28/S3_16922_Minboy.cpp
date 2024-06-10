#include <iostream>

using namespace std;

int N, ans;
bool Visit[1111];
int Arr[4] = {1, 5, 10, 50};

void dfs(int cnt, int idx, int sum) {
    if (cnt == N) {
        if (!Visit[sum]) {
            Visit[sum] = true;
            ans++;
        }
        return;
    }

    for (int i = idx; i < 4; i++) {
        dfs(cnt + 1, i, sum + Arr[i]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    dfs(0, 0, 0);

    cout << ans << "\n";

    return 0;
}