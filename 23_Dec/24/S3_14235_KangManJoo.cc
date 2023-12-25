#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    int n, cost, a;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 0) {
            if (pq.empty()) {
                cout << -1;
            } else {
                cout << pq.top();
                pq.pop();
            }
            cout << '\n';
        } else {
            for (int i = 0; i < a; i++) {
                cin >> cost;
                pq.push(cost);
            }
        }
    }
}