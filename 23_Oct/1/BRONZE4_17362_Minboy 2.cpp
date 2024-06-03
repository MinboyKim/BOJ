#include <iostream>

using namespace std;

long long n;
int Arr[8] = {1, 2, 3, 4, 5, 4, 3, 2};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    cout << (n >= 8 ? Arr[(n % 8 ? n % 8 - 1 : n % 8 + 1)] : Arr[n - 1]) << "\n";

    return 0;
}