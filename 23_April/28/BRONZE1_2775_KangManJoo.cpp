#include <bits/stdc++.h>

using namespace std;

int t,k,n;
int floor_room[15][15];


void solve(){
    int i=0;
    for(int j=0; j<15;j++) floor_room[i][j]=j;
    for(int i=1; i<15;i++){
        for(int j=0; j<15;j++){
            for(int k=0; k<=j; k++)
                floor_room[i][j]+=floor_room[i-1][k];
        }
    }
}

int main(){
    cin>>t;
    solve();
    while(t--){
        cin>>k>>n;
        cout<<floor_room[k][n]<<'\n';
    }

}