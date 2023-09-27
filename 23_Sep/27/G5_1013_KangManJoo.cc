#include <bits/stdc++.h>

using namespace std;

//(100+1+ | 01)+
int arr[201];
string s;

bool solve(){
    char cur;
    for(int i=0; i<s.size(); i++){
        int flag=0;
        if(arr[i]==1){
            int cnt=0;
            while(true){
                if(arr[i+1]==0){
                    cnt++;
                }
                else if(arr[i+1]==1 && cnt<2){
                    return false;
                }
                else{

                }
                i++;
            }
        }
        else{
            if(i!=s.size()-1 && arr[i+1]==1){
                i++;
            }
            else{
                return false;
            }
        }
    }

    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        for(int i=0; i<s.size(); i++){
            arr[i]=s[i]-48;
        }
        if(solve()) cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
    }
}