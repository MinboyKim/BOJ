#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,a=0,b=0;
    cin >> n;
    int t = 1;
    while (a * 2 + b * 2 + a * b + 4 < n) {
        if(t==1){
            a++;
        }
        else{
            b++;
        }
        t *= -1;
    }
    cout << (a + 1) * 2 + (b + 1) * 2;
}