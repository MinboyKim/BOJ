#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    int n,m,cnt=0;
    string query,next;

    cin>>n>>m;
    cin>>query;
    string match = "I";

    for(int i=0; i<n; i++){
       match+="OI";
    }
    int pt,pt2;
    while(query.find(match)!=string::npos){
        pt=query.find(match);
        query=query.substr(pt+match.length());
        cnt++;
        pt2=0;
        while(true){
            if(query.length()-pt2>=2){
                if(query.substr(pt2,2)=="OI"){
                    cnt++;
                    pt2+=2;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        query=query.substr(pt2);
    }
    cout<<cnt;

    
}