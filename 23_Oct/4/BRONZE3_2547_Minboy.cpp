#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull T, N;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;
    ull a;
    while (T--) {
        ull temp = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a;
            temp += a % N;
        }
        cout << (temp % N == 0 ? "YES\n" : "NO\n");
    }
    return 0;
}