#include <bits/stdc++.h>

using namespace std;


int arr[36];

int main(){
    int n;
    string name;
    char ansC='N';
    cin>>n;
    while(n--){
        cin>>name;
        arr[name[0]-'a']++;
    }
    for(int i=0; i<36; i++){
        if(arr[i]>=5){
            int ans=i+'a';
            ansC=ans;
            cout<<ansC;
        }
    }
    if(ansC=='N'){
        cout << "PREDAJA";
    }

}