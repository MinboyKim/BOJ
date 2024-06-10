#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, B, H, W, p, a;
vector<int> v;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> B >> H >> W;
    for (int i = 0; i < H; i++) {
        bool flag = false;
        cin >> p;
        for (int i = 0; i < W; i++) {
            cin >> a;
            if (a >= N) flag = true;
        }
        if (flag) v.push_back(p);
    }

    sort(v.begin(), v.end());
    if (v.size() == 0 || v[0] * N > B) {
        cout << "stay home\n";
        return 0;
    }
    cout << v[0] * N << "\n";

    return 0;
}