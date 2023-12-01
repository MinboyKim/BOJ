#include <bits/stdc++.h>

using namespace std;


int arr[40];

int main(){
    string str;
    cin>>str;

    for(auto s: str){
        arr[s-65]++;
    }

    if(str.size()%2==0){
        for (int i = 0; i <= 25; i++) {
            if(arr[i] % 2 !=0){
                cout << "I'm Sorry Hansoo";
                exit(0);
            }
        }
    }
    else{
        int cnt=0;
        for (int i = 0; i <= 25; i++) {
            if (arr[i] % 2 == 1) {
                cnt++;
            }
        }
        if(cnt!=1){
            cout << "I'm Sorry Hansoo";
            exit(0);
        }
    }

    for(int i=0; i<=25; i++){
        for(int j=0; j<arr[i]/2; j++){
            cout<<char(i+65);
        }
    }

    for (int i = 0; i <= 25; i++) {
        for (int j = 0; j < arr[i] % 2; j++) {
            cout << char(i + 65);
        }
    }

    for (int i = 25; i >=0; i--) {
        for (int j = 0; j < arr[i] / 2; j++) {
            cout << char(i + 65);
        }
    }
}