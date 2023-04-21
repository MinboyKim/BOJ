#include <bits/stdc++.h>

using namespace std;

int n,cur;
int sequence[100'001];
stack<int> stk;
vector<char> answer;

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++) cin>>sequence[i];

    int i=0;
    stk.push(-1);
    while(true){
        if(cur==n) break;
        
        if(stk.top()>sequence[cur]){
            cout<<"NO";
            return 0;
        }
        else if(stk.top()==sequence[cur]) {
            answer.push_back('-');
            stk.pop();
            cur++;
        }
        else{
            i++;
            stk.push(i);
            answer.push_back('+');
        }
        if(i>100'000){
            cout<<"NO";
            return 0;
        } 
    }
    
    for(auto& i: answer) cout<<i<<'\n';
    return 0;
}