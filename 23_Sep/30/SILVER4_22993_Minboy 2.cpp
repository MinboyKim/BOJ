#include <iostream>
#include <algorithm>

using namespace std;

long long N, JW, cnt;
long long Arr[101'010];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> JW;
    for (int i = 0; i < N - 1; i++)
        cin >> Arr[i];

    sort(Arr, Arr + N - 1);
    for (int i = 0; i < N - 1; i++) {
        if (JW > Arr[i]) {
            JW += Arr[i];
            cnt++;
        }
    }

    cout << (cnt == N - 1 ? "Yes\n" : "No\n");

    return 0;
}