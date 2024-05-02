#include <bits/stdc++.h>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;

    a = a / (b * b);
    if(a>25){
        cout << "Overweight";
    }
    else if(a<18.5){
        cout << "Underweight";
    }
    else{
        cout << "Normal weight";
    }
}