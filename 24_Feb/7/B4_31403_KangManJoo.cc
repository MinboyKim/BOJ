#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b, c;
    string ab;
    int ia, ib, ic;
    cin >> a >> b >> c;
    ia = stoi(a);
    ib = stoi(b);
    ic = stoi(c);
    ab = a + b;
    cout << ia + ib - ic << '\n';
    ia = stoi(ab);
    cout << ia - ic;
}