#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    string a, b;
    cin >> t;
    while(t--){
        int cntz = 0;
        int cnto = 0;
        cin >> a >> b;
        for (int i = 0; i < a.size(); i++)
        {
            if(a[i]!=b[i] && a[i]=='0'){
                cntz++;
            }
            else if(a[i]!=b[i] && a[i]=='1'){
                cnto++;
            }
        }
        cout << max(cntz, cnto) << '\n';
    }
}