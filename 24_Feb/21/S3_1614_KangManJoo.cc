#include <bits/stdc++.h>

using namespace std;

// 12345432
long long sum;
int main() {
    long long n, countMax;
    cin >> n >> countMax;

    long long cycle;
    if (n == 1) {
        cycle = countMax;
    } else if (n == 5) {
        cycle = countMax;
        sum += 4;
    } else {
        cycle = countMax / 2;
        if (countMax % 2 == 0) {
            sum += n - 1;
        } else {
            sum += 5 + 5 - n - 1;
        }
    }
    sum += cycle * 8;
    cout << sum;
}