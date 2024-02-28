#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    int count = 0;
    int result = 0;
    int pCount = 0;
    int kill = 0;
    for (auto s : str) {
        if (s == 'P') {
            if (count == 1) {
                kill = 1;
            }
            pCount++;
        } else if (s == 'W') {
            count++;
        }
        if (count == 2) {
            if (kill) {
                result = 6;
                break;
            } else if (pCount % 2 == 0) {
                result = 5;
            } else {
                result = 1;
            }
            break;
        }
    }
    cout << result;
}