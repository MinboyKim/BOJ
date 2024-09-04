#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a % b);
}

int main(){
    int r, g;
    cin >> r >> g;
    int t = gcd(r, g);

    for (int i = 1; i <= t / 2; i++){
        if(t%i==0){
            cout << i << " " << r / i << " "<<g / i<<'\n';
        }
    }
    cout << t << " " << r / t << " " << g / t;
}