#include <bits/stdc++.h>

using namespace std;


int n,cnt;
int arr[1010];
int result;
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>> arr[i];
        result=result^arr[i];
    }
    int i=0,highestBit=-1;
    while(result){
        if(result & 1) highestBit=i;
        result=result>>1;
        i++;
    }

    int isBitExist=1;
    for(int i=0; i<highestBit; i++){
        isBitExist= isBitExist << 1;
    }
    

    if(highestBit==-1) cout<<"0";
    else{
        for(int i=0; i<n; i++){
            if(arr[i]&isBitExist) cnt++;
        }
        cout<<cnt;
    }
    return 0;
    
}