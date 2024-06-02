#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    while(b--){
        if(a%2==0){
            a = (a / 2) ^ 6;
        }
        else{
            a = (a * 2) ^ 6;
        }
    }
    cout << a;
}