#include <bits/stdc++.h>

using namespace std;

int main(){
    while(true){
        string str;
        getline(cin, str);

        if(str=="END"){
            break;
        }
        else{
            for (int i = str.size() - 1; i >= 0; i--)
            {
                cout << str[i];
            }
        }
        cout << '\n';
    }
}