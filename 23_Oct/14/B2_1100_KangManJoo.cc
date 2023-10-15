#include <bits/stdc++.h>

using namespace std;


int main(){
    string s;
    int cnt=0;
    for(int i=0; i<8; i++){
        cin>>s;
        for(int j=0; j<8; j++){
            if(i%2==0){
                if (j % 2 == 0 && s[j] == 'F')
                    cnt++;
            }
            else{
                if (j % 2 != 0 && s[j] == 'F')
                    cnt++;
            }
        }
    }

    cout<<cnt;
}