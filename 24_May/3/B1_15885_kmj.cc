#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long res = n;

    for (long long i = 1; i <= n; i++){
        res -= i;
        if(res<0){
            cout << i-1;
            break;
        }
        if(res==0){
            cout << i;
            break;
        }
    }
}