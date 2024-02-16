#include <iostream>

using namespace std;

int N, M;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    cout << min(N / 2, M / 2) << "\n";

    return 0;
}