#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

priority_queue<int> pq;
vector<pii> v;

bool cmp(pii a, pii b) { return a.second > b.second; }


int main() {
    int n;
    cin >> n;
    pii a;
    if (n == 0) {
        cout << 0;
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        cin >> a.first >> a.second;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), cmp);

    int maxDay = v[0].second;

    int idx = 0;
    long long result = 0;
    for (int i = maxDay; i >= 1; i--) {
        for (int j = idx; j < v.size(); j++) {
            if (v[j].second == i) {
                pq.push(v[j].first);
                idx++;
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