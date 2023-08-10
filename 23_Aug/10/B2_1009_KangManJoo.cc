#include<bits/stdc++.h>

using namespace std;

vector<int> arr[11];


int main(){
    arr[1].push_back(1);
    arr[2]={2,4,8,6};
    arr[3]={3,9,7,1};
    arr[4]={4,6};
    arr[5]={5};
    arr[6]={6};
    arr[7]={7,9,3,1};
    arr[8]={8,4,2,6};
    arr[9]={9,1};
    arr[10]={10};

    int t,a,b;
    cin>>t;

    while(t--){
        cin>>a>>b;
        a=a%10;
        if(!a) a=10;
        b--;
        b%=arr[a].size();
        cout<<arr[a][b]<<'\n';
    }
}