#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    double a, b, min;
    cin >> a >> b;
    min = a / b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a/b < min)
            min = a / b;
    }
    cout<<fixed;
    cout.precision(2);
    cout << min * 1000;
}