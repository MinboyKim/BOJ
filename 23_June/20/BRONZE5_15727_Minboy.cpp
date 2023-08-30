#include <iostream>

using namespace std;

int L;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> L;
    if (L % 5 != 0) cout << L / 5 + 1 << "\n";
    else cout << L / 5 << "\n";
    
    return 0;
}