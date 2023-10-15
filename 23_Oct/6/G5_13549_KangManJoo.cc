#include <bits/stdc++.h>

using namespace std;

int arr[100100];
int visited[100100];
int n, k;

deque<pair<int, int>> dq;

void bfs(int cur) {
    int next, cnt = 0;
    dq.push_front({cur, 0});
    pair<int, int> pii;
    while (!dq.empty()) {
        pii = dq.front();
        dq.pop_front();
        cur = pii.first;
        cnt = pii.second;
        if (cur == k) {
            cout << cnt;
            break;
        }
        arr[cur] = cnt;
        next = cur - 1;
        if (next >= 0 && next != n) {
            if (!arr[next] || (arr[next] > cnt)) {
                dq.push_back({next, cnt + 1});
            }
        }
        next = cur + 1;
        if (next <= 100000 && next != n)
            if (!arr[next] || arr[next] > cnt) {
                dq.push_back({next, cnt + 1});
            }

        next = cur * 2;
        if (next <= 100000 && next != n) {
            if (!arr[next])
                dq.push_front({next, cnt});
        }
    }
    return;
}

int main() {
    cin >> n >> k;

    bfs(n);
}