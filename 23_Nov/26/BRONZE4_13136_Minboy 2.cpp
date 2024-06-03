#include <iostream>

using namespace std;

long long R, C, N, x, y;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> N;

    x = R / N;
    if (R % N) x++;
    y = C / N;
    if (C % N) y++;

    cout << x * y << "\n";

    return 0;
}