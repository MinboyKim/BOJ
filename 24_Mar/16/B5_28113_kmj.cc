#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a<=c){
        if(b==c){
            cout << "Anything";
        }
        else if(b<c){
            cout << "Bus";
        }
        else{
            cout << "Subway";
        }
    }
    else{
        cout << "Bus";
    }
}