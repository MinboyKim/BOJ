#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int o = b;
    int x = a - b;

    int sum = 0;
    sum += min(c, o);
    sum += min(a - c, x);

    cout << sum;
}