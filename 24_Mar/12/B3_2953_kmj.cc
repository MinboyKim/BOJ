#include <bits/stdc++.h>

using namespace std;

int main() {
    int maxs = 0, idx = 0,a;
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            cin >> a;
            sum += a;
        }
        if(sum>maxs){
            idx = i + 1;
            maxs = sum;
        }
    }
    cout << idx << " " << maxs;
}