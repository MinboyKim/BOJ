#include <bits/stdc++.h>

using namespace std;

char arr[5] = {'K','O','R','E','A'};
int main(){
    string str;

    cin >> str;

    int cur = 0;
    for(auto i:str)
    {
        if(i==(arr[cur%5])){
            cur++;
        }
    }


    cout << cur;
}