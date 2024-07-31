#include <bits/stdc++.h>

using namespace std;

int main(){
    string a, b,c="",d="";
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--){
        c += a[i];
        d+=b[i];
    }

    cout << max(stoi(c), stoi(d));
}