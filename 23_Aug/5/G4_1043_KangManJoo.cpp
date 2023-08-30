#include <bits/stdc++.h>

using namespace std;

int n,m,knowNum,k,cnt;
int knowList[55];
int partyHumanList[55][55];
int Union[55];

int findUnion(int a){
    if(Union[a]==a) return a;
    else{
        return findUnion(Union[a]);
    }
}

void makeUnion(int a, int b){
    a=findUnion(a);
    b = findUnion(b);

    Union[b]=a;
}   


int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin>>n>>m;
    cin>>knowNum;

    for(int i=1; i<=n; i++){
        Union[i]=i;
    }

    while(knowNum--){
        cin>>k;
        knowList[k]=1;
    }

    for(int i=0; i<m; i++){
        cin>>knowNum;
        for(int j=0; j<knowNum; j++){
          cin >> k;
          partyHumanList[i][j] = k;
        }
    }

    for(int i=0; i<m; i++){
        int knowInclude=0;
        for(int j=0; j<51; j++){
            if(partyHumanList[i][j]==0) break;

            if(knowList[findUnion(partyHumanList[i][j])]==1) {
                knowInclude=j;
                break;
            }
        }
        if(knowInclude){
             for (int j = 0; j < 51; j++) {
                if (partyHumanList[i][j] == 0) break;

                if(j==knowInclude) continue;
                makeUnion(partyHumanList[i][knowInclude],partyHumanList[i][j]);
             }
        }
        else{
             for (int j = 1; j < 51; j++) {
                if (partyHumanList[i][j] == 0) break;
                makeUnion(partyHumanList[i][0], partyHumanList[i][j]);
             }
        }
    }


    for (int i = 0; i < m; i++) {
        int flag=0;
        for (int j = 0; j < 51; j++) {
             if (partyHumanList[i][j] == 0) break;
             if (knowList[findUnion(partyHumanList[i][j])] == 1) {
                flag=1;
                break;
             }
        }
        if(flag==0) cnt++;
    }

    cout<<cnt;
    return 0;
}