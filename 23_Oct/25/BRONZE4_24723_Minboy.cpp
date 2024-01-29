#include <iostream>

using namespace std;

int N;
int ans[6] = {0, 2, 4, 8, 16, 32};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    cout << ans[N] << "\n";

    return 0;
}