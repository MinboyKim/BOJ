#include <bits/stdc++.h>

using namespace std;

int main() {
    int t,a,b,c;
    cin >> t;
    while(t--){
        cin >> a;
        for (int i = 0; i < a; i++){
            cin >> b >> c;
            cout << b + c << " " << b * c<<'\n';
        }
    }
}