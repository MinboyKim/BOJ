#include <bits/stdc++.h>

using namespace std;

deque<int> dq;
vector<int> ans;
int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    int cnt = 1;
    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();
        if (cnt == k) {
            ans.push_back(cur);
            cnt = 1;
            continue;
        }
        dq.push_back(cur);

        cnt++;
    }

    for (int i = 0; i < ans.size(); i++) {
        if (i == 0)
            cout << "<";
        if (i == ans.size() - 1)
            cout << ans[i] << ">";
        else
            cout << ans[i] << ", ";
    }
}