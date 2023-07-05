#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int num;
    int gold;
    int silver;
    int bronze;
} country;

int N, K, idx;
country Arr[1111];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    int a,b,c,d;
    for(int i = 1;i<=N;i++) {
        cin >> a >> b >> c >> d;
        Arr[i] = {a,b,c,d};
        if (a == K) idx = i;
    }

    int ans = 1;
    for(int i = 1;i<=N;i++) {
        if (Arr[i].gold > Arr[idx].gold) ans++;
        else if (Arr[i].gold == Arr[idx].gold) {
            if (Arr[i].silver > Arr[idx].silver) ans++;
            else if (Arr[i].silver == Arr[idx].silver) {
                if (Arr[i].bronze > Arr[idx].bronze) ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}