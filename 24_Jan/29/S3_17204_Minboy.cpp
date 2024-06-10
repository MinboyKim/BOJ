#include <iostream>
#include <vector>

using namespace std;

int N, K;
int Arr[222];

void dfs(int cur, int d) {
    if (cur == K) {
        cout << d << "\n";
        return;
    }
    if (d >= N) {
        cout << -1 << "\n";
        return;
    }
    dfs(Arr[cur], d + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> Arr[i];
    }

    dfs(0, 0);

    return 0;
}