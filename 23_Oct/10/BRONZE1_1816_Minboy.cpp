#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

ull N, S;
ull Arr[1'010'101];
vector<ull> prime;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i <= 1'000'000; i++) {
        if (!Arr[i]) {
            prime.push_back(i);
            for (int j = i * 2; j <= 1'000'000; j += i)
                Arr[j] = 1;
        } else
            continue;
    }

    cin >> N;
    while (N--) {
        cin >> S;
        bool flag = true;
        for (auto &i : prime)
            if (S % i == 0) {
                flag = false;
                break;
            }
        cout << (flag ? "YES\n" : "NO\n");
    }

    return 0;
}