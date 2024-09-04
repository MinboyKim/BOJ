#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int main(){
    int n,a;
    cin >> n;
    while(n--){
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    int cnt = 1;
    int min = -1;

    for(auto i: arr){
        if(min<i){
            min = i;
        }
        if(cnt==min+1){
            break;
        }

        cnt++;
    }
    cout << cnt;
}