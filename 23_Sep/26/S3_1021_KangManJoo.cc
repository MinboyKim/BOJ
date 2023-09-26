#include <bits/stdc++.h>

using namespace std;

deque<int> dq;
int arr[51];

int main() {
    int n, m, t, cost = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    for (int i = 0; i < m; i++) {
        cin >> t;
        arr[i] = t;
    }

    for (int i = 0; i < m; i++) {
        t = arr[i];
        int cnt = 0;
        while (true) {
            int head = dq.front();
            if (head == t) {
                dq.pop_front();
                if (cnt > ((n - i) / 2)) {
                    cnt = (n - i) - cnt;
                }
                cost += cnt;
                break;
            }
            dq.pop_front();
            dq.push_back(head);
            cnt++;
        }
    }

    cout << cost;
}