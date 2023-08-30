#include <bits/stdc++.h>

using namespace std;

stack<int> stk;

int t,n;
int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>t;
    char oper;
    int query;


    while(t--){        
       priority_queue<int> upperPQ; //default -> less 
       priority_queue<int,vector<int>,greater<int>> lowerPQ;
       map<int,int> data;
        cin>>n;
        while(n--){

            cin>>oper>>query;
            if(oper=='I'){
                upperPQ.push(query);
                lowerPQ.push(query);
                if(data.find(query)==data.end()){
                    data[query]=1;
                }
                else{
                    data[query]++;
                }
            }
            else if(query==-1){
                while(!lowerPQ.empty()){
                    query=lowerPQ.top();
                    lowerPQ.pop();
                    if(data.find(query)!=data.end()&&data[query]>0){
                        data[query]--;
                        break;
                    }
                    else{
                        continue;
                    }
                }  
            }
            else if(query==1){
                while(!upperPQ.empty()){
                    query=upperPQ.top();
                    upperPQ.pop();
                    if(data.find(query)!=data.end()&&data[query]>0){
                        data[query]--;
                        break;
                    }
                    else{
                        continue;
                    }
                }      
            }            
        }
        int flag=0;
        while(!upperPQ.empty()){
            if(data[upperPQ.top()]!=0){
                cout<<upperPQ.top()<<" ";
                flag=1;
                break;
            }
            else{
                upperPQ.pop();
            }
        }
        while(!lowerPQ.empty()){
            if(data[lowerPQ.top()]!=0){
                cout<<lowerPQ.top()<<'\n';
                break;
            }
            else{
                lowerPQ.pop();
            }
        }
        if(flag==0){
            cout<<"EMPTY"<<'\n';
        }
    }   
}