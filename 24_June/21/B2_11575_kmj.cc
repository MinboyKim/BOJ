#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,a,b;
    string str;
    cin >> t;
    while(t--){
        cin >> a >> b;

        cin >> str;
        for(auto s: str){
            int nex = ((s - 'A') * a + b) % 26;
            cout << char(nex+'A');
        }
        cout << '\n';
    }
}