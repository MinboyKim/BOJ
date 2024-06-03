#include <iostream>
#include <vector>

using namespace std;

int n, k, cnt;
vector<int> v;
bool flag = false;

void dfs(int sum) {
    if (sum == n) {
        if (cnt == k - 1) {
            for (int i = 0; i < v.size(); i++) {
                cout << v[i];
                if (i != v.size() - 1) cout << '+';
            }
            cout << "\n";
            flag = true;
        }
        cnt++;
        return;
    }
    for (int i = 1; i <= 3; i++) {
        sum += i;
        v.push_back(i);
        if (sum <= n) {
            dfs(sum);
            if (flag) return;
        }
        v.erase(v.end() - 1);
        sum -= i;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;

    dfs(0);

    if (!flag) cout << -1 << "\n";

    return 0;
}