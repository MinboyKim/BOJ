#include <bits/stdc++.h>

using namespace std;

int n;
map<string, int> arr;
string str, io;
vector<string> ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str >> io;
        if (io == "enter")
            arr[str]=1;
        else if (io == "leave") {
            arr[str] = 0;
        }
    }


    for (auto i : arr) {
        if(i.second==1){
            ans.push_back(i.first);
        }
    }

    sort(ans.begin(), ans.end(),greater<>());

    for(auto i:ans){
        cout << i << '\n';
    }
}