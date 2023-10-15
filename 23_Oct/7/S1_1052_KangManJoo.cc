#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;

    cin >> n >> k;

    // 비트가 1인 자릿수가 k개를 넘을경우 1을 더해준다. 몇번 더해줘야되는지
    // 구하면됨

    int tmp, bottle = 0;
    int bitSize = sizeof(n) * 8;
    while (true) {
        int cnt = 0;
        for (int i = 0; i < bitSize; i++) {
            tmp = 1 & (n >> i);
            if (tmp)
                cnt++;
        }
        if (cnt <= k)
            break;
        else {
            bottle++;
            n++;
        }
    }
    cout << bottle;
}