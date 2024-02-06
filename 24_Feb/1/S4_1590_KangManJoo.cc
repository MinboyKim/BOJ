#include <bits/stdc++.h>

using namespace std;

int bus[3000300];
int main() {
    int n, start,s,k,c;
    cin >> n >> start;
    for (int i = 0; i < n; i++) {
        cin >> s >> k >> c;
        for (int j = 0; j < c; j++){
            bus[s + k * j] = 1;
        }
    }

    for (int i = start; i < 2000200; i++){
        if(bus[i]){
            cout << i - start;
            exit(0);
        }
    }
    cout << -1;
}