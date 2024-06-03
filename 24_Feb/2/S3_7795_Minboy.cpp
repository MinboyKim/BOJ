#include <iostream>
#include <algorithm>

using namespace std;

int T;
int Arr1[20'202];
int Arr2[20'202];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;
    int A, B;
    while (T--) {
        cin >> A >> B;
        for (int i = 0; i < A; i++) {
            cin >> Arr1[i];
        }
        for (int i = 0; i < B; i++) {
            cin >> Arr2[i];
        }

        sort(Arr1, Arr1 + A);
        sort(Arr2, Arr2 + B);

        int ans = 0;
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                if (Arr1[i] <= Arr2[j]) {
                    ans += j;
                    break;
                }
                if (j == B - 1) ans += B;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}