#include <algorithm>
#include <iostream>

using namespace std;

int N, ans;
int Arr[30'303];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> Arr[i];

    for (int i = 0; i < N; i++) {
        int temp = 0;
        for (int j = i + 1; j < N; j++) {
            if (Arr[i] >= Arr[j])
                temp++;
            else
                break;
        }
        ans = max(ans, temp);
    }

    cout << ans << "\n";

    return 0;
}