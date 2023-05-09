#include <bits/stdc++.h>

using namespace std;

int t,len;
string q,arrayS;
char *ptr;
deque<int> arr;
vector<string> splitS;


void solve(){
    int plag=1;
    for(auto &query:q){
        if(query=='R') plag*=-1;
        else{
            if(arr.empty()){
                cout<<"error"<<'\n'; 
                return;
            }
            if(plag==1){
                arr.pop_front();
            }
            else{
                arr.pop_back();
            }
        }
    }
   
   cout<<"[";
    while(!arr.empty()){
        if(plag==1){
            cout<<arr.front();
            arr.pop_front();
        }
        else{
            cout<<arr.back();
            arr.pop_back();
        }
        if(!arr.empty()) cout<<",";
    }
    cout<<"]"<<'\n';
}

void init(){
    while(!arr.empty()) arr.pop_back();
 
    cin>>q>>len>>arrayS;

    arrayS=arrayS.substr(1);
    arrayS=arrayS.substr(0,arrayS.size()-1);   

    char delimiter=',';
    istringstream ss(arrayS);
    string stringBuffer;
    while (getline(ss, stringBuffer, ',')){   //, 기준으로 문자열 자르기
        arr.push_back(stoi(stringBuffer));
    }    
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        init();
        solve();
    }

}