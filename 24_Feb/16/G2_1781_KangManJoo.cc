#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int arr[200200];

priority_queue<int> pq;
vector<pii> v;
int main() {
    int n, dead, cup, today = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dead >> cup;
        v.push_back({dead, cup});
    }

    sort(v.begin(), v.end());

    int result = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = v.size() - 1; j >= 0; j--) {
            if (v[j].first == i) {
                pq.push(v[j].second);
                v.pop_back();
            } else {
                break;
            }
        }
        if (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    }
    cout << result;
}