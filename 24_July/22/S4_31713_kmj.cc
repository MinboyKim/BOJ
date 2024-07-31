#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        int needA = 0, needB = 0;
        cin >> a >> b;
        if(a*3<=b && b<=a*4){
            cout << 0<<'\n';
            continue;
        }
        else if(a*4<b){
            needA = b / 4-a;
            if(b%4>0){
                needA++;
            }
            a += needA;
        }

        if(b<a*3){
            needB = a * 3 - b;
        }
        int k = needA+needB;

        cout << k << '\n';
    }
}