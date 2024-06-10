#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int K;
int Arr[2222];
vector<int> tree[22];

void recursion(int l, int r, int d) {
    if (d >= K) return;
    if (l == r) {
        tree[d].push_back(Arr[l]);
        return;
    }

    int m = (l + r) / 2;
    if (m < 0 || m >= pow(2, K) - 1) return;
    tree[d].push_back(Arr[m]);
    recursion(l, m - 1, d + 1);
    recursion(m + 1, r, d + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> K;

    for (int i = 0; i < pow(2, K) - 1; i++)
        cin >> Arr[i];

    recursion(0, pow(2, K) - 1, 0);

    for (int i = 0; i < K; i++) {
        for (auto &j : tree[i])
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}