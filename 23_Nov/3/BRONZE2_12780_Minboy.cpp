#include <iostream>
#include <string>

using namespace std;

string H, N;
int ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> H >> N;
    auto pos = H.find(N, 0);
    while (pos != string::npos) {
        pos = H.find(N, pos + 1);
        ans++;
    }

    cout << ans << "\n";

    return 0;
}