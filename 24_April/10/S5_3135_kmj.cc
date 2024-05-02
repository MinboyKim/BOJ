#include <bits/stdc++.h>

using namespace std;

int Min = 9999;
int main() {
    int a, b;
    int n,z;
    cin >> a >> b >> n;
    for (int i = 0; i < n; i++){
        cin >> z;
        Min = min(Min, abs(z - b) + 1);
    }
    Min = min(Min, abs(a - b));
    cout << Min;
}