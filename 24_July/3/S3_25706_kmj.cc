#include <bits/stdc++.h>

using namespace std;

int arr[400200];

vector<int> v;
vector<int> ans;

int main(){
    int n,a;
    cin >> n;
    while(n--){
        cin>>a;
        v.push_back(a);
    }

    for (int i = v.size() - 1; i >= 0; i--){
        if(v[i]==0){
            ans.push_back(arr[i+1]+1);
            arr[i]=arr[i+1]+1;
            continue;
        }
        ans.push_back(arr[v[i] + i+1]+1);
        arr[i]=arr[v[i] + i+1]+1;
    }

    for (int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
}