#include <iostream>

using namespace std;

int n;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (true) {
        cin >> n;
        if (n == 0) return 0;
        int temp = 0;
        for (int i = 1; i <= n; i++)
            temp += i;
        cout << temp << "\n";
    }

    return 0;
}