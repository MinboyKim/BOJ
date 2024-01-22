#include <bits/stdc++.h>

using namespace std;

int main() {
    int Min = 0;
    int n, p, tmp;
    cin >> n >> p;
    if (n >= 20) {
        tmp = p * 0.75;
        Min = min(p - 2000, tmp);
    } else if (n >= 15) {
        tmp = p * 0.9;
        Min = min(p - 2000, tmp);
    } else if (n >= 10) {
        tmp = p * 0.9;
        Min = min(p - 500, tmp);
    } else if (n >= 5) {
        Min = p - 500;
    } else {
        Min = p;
    }
    if (Min < 0)
        cout << "0";
    else {
        cout << Min;
    }
}