#include <bits/stdc++.h>

using namespace std;

int n,k,loc,t,tmp;
int arr[200002][31];

int main(){
    cin>>n>>k;
    tmp=k;
    while (tmp) {
      int Kfirstbit = tmp & 1;
      tmp = tmp >> 1;
      if (Kfirstbit == 1) {
        arr[0][loc] = 1;
      }
      loc++;
    }

    for(int i=1; i<=n; i++){
        cin>>t;
        loc=0;
        while(t){
            int Tfirstbit =t&1;
            t=t>>1;
            if( Tfirstbit==1){
                arr[i][loc]=1;
            }
            loc++;
        }
    }

    tmp=k;

    int start=1,end=0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<31; j++){
            if(arr[i][j]==arr[0][j]){
                tmp &= ~(1 << j);
            }
            else if(arr[i][j]==1 && arr[0][j]==0){
                tmp=k;
                start=i+1;
                break;
            }
        }
        if(tmp==0){
            end=i;
            break;
        }
    }

    if(!end) cout<<-1;
    else cout<<start<<" "<<end;

}