#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A, B, N;
vector<int> ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        if (A <= B) ans.push_back(B);
    }

    if (ans.size() == 0) {
        cout << -1 << "\n";
        return 0;
    }

    sort(ans.begin(), ans.end());

    cout << ans[0] << "\n";

    return 0;
}