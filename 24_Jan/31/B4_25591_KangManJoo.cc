#include <bits/stdc++.h>

using namespace std;

int main() { int a, b,c,d,q,r,n,m;
    cin >> n >> m;
    a = 100 - n;
    b = 100 - m;
    c = 100 - a - b;
    d = a * b;
    q = d / 100;
    r = d % 100;
    cout << a << " " << b << " " << c << " " << d << " " << q << " " << r<<'\n';
    cout << c + q << " " << r;
}