#include <bits/stdc++.h>

using namespace std;

char arr[10];

int strs[10];

int c[30];
string str;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            c[str[j] - 'A'] += pow(10, str.size() - j - 1);
        }
    }
    sort(c, c + 30, greater<>());

    int result = 0;
    for (int i = 0; i < 10; i++) {
        result += c[i] * (9 - i);
    }
    cout << result;
}