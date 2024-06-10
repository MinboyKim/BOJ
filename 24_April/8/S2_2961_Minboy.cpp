#include <iostream>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

int N, ans = 1'999'999'999;
pii Arr[11];
bool Visit[11];

int check() {
    int sour = 1, bitter = 0;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (Visit[i]) {
            flag = true;
            sour *= Arr[i].first;
            bitter += Arr[i].second;
        }
    }
    if (!flag) return 1'999'999'999;
    return abs(sour - bitter);
}

void dfs(int cur) {
    ans = min(ans, check());
    for (int i = cur; i < N; i++) {
        Visit[i] = true;
        dfs(cur + 1);
        Visit[i] = false;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> Arr[i].first >> Arr[i].second;
    }

    dfs(0);

    cout << ans << "\n";

    return 0;
}