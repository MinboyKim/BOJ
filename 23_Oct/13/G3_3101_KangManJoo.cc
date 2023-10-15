#include <bits/stdc++.h>

using namespace std;

int row = 1, col = 1;
long long ans=1;
long long sum = 1;
int lv;
int n, k;

void calc(char c) {
    int flag=0;
    if (c == 'D') {
        row++;
        lv = row + col - 1;
        if (lv > n) {
            flag=1;
            lv = n - (lv - n);
        }
        sum += lv;
    } else if (c == 'R') {
        col++;
        lv = row + col - 1;
        if (lv > n) {
            flag = 1;

            lv = n - (lv - n);
        }
        sum += lv;

    } else if (c == 'L') {
        col--;
        sum -= lv;
        lv = row + col - 1;
        if (lv > n) {
            flag = 1;

            lv = n - (lv - n);
        }
    } else if (c == 'U') {
        row--;
        sum -= lv;
        lv = row + col - 1;
        if (lv > n) {
            flag = 1;

            lv = n - (lv - n);
        }
    }

    if (lv % 2 != 0) {
        ans += sum - (lv - col);
        if (flag) {
            ans -= n - lv;
        }
    } else {
        ans += sum - (col - 1);
        if (flag) {
            ans += n - lv;
        }
    }

}

int main() {
    string s;
    cin >> n >> k >> s;

    for (auto i : s) {
        calc(i);
    }
    cout << ans;
}