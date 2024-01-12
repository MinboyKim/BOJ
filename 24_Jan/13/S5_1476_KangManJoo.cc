#include <bits/stdc++.h>

using namespace std;

int e, s, m;
int main() {
    cin >> e >> s >> m;
    e %= 15;
    s %= 28;
    m %= 19;
    
    int cur = 1;
    while (true) {
        if(cur%15==e&&cur%28==s&&cur%19==m){
            break;
        }
        cur++;
    }
    cout << cur;
}