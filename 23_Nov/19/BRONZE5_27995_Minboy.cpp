#include <iostream>

using namespace std;

int N, M;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    cout << (N * 100 >= M ? "Yes\n" : "No\n");

    return 0;
}