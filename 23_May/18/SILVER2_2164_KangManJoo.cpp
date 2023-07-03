#include <iostream>
#include <queue>

using namespace std;


int n;
queue<int> arr;
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) arr.push(i);

    int tmp;
    int turn=1;
    while(!arr.empty()){
        if(turn==1){
            tmp=arr.front();
            arr.pop();
        }
        else{
            tmp=arr.front();
            arr.pop();
            arr.push(tmp);
        }
        turn*=-1;
    }    
    cout<<tmp;
}