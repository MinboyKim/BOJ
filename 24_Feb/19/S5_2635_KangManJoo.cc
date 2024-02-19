// 첫 번째 수로 양의 정수가 주어진다.두 번째 수는 양의 정수 중에서 하나를
// 선택한다
//     .세 번째부터 이후에 나오는 모든 수는 앞의 앞의 수에서 앞의 수를 빼서
//         만든다.예를 들어,
//     세 번째 수는 첫 번째 수에서 두 번째 수를 뺀 것이고,
//     네 번째 수는 두 번째 수에서 세 번째 수를 뺀 것이다.음의 정수가
//     만들어지면, 이 음의 정수를 버리고 더 이상 수를 만들지 않는다.

#include <bits/stdc++.h>

using namespace std;
int n;
int maxCnt = 0;
int maxIdx;

void solve(int idx) {
    int cnt = 1;
    int pre = n;
    int cur = idx;
    while (true) {
        int next = pre - cur;
        if (next >= 0) {
            cnt++;
            pre = cur;
            cur = next;
        } else {
            break;
        }
    }
    if (cnt > maxCnt) {
        maxCnt = cnt;
        maxIdx = idx;
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        solve(i);
    }
    cout << maxCnt + 1 << '\n';
    int pre = n;
    int cur = maxIdx;
    cout << n << " " << cur << " ";
    while (true) {
        int next = pre - cur;
        if (next < 0)
            break;
        cout << next << " ";
        pre = cur;
        cur = next;
    }
}