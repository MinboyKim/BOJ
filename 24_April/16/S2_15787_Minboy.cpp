#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> s;
int N, M, ans, a, b, c;
int Arr[101'010];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        if (a <= 2) cin >> c;
        if (a == 1) {
            Arr[b] |= (1 << c);
        } else if (a == 2) {
            Arr[b] &= ~(1 << c);
        } else if (a == 3) {
            Arr[b] = Arr[b] << 1;
            Arr[b] &= ((1 << 21) - 1);
        } else {
            Arr[b] = Arr[b] >> 1;
            Arr[b] &= ~1;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (s.find(Arr[i]) == s.end()) {
            ans++;
            s.insert(Arr[i]);
        }
    }

    cout << ans << "\n";
    return 0;
}