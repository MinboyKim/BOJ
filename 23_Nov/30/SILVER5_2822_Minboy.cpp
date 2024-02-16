#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

pii Arr[10];
int sum;
vector<int> ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int a;
    for (int i = 1; i <= 8; i++) {
        cin >> a;
        Arr[i] = {a, i};
    }

    sort(Arr + 1, Arr + 9);

    for (int i = 8; i >= 4; i--) {
        sum += Arr[i].first;
        ans.push_back(Arr[i].second);
    }

    sort(ans.begin(), ans.end());

    cout << sum << "\n";
    for (auto &i : ans)
        cout << i << " ";

    return 0;
}