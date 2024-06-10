#include <bits/stdc++.h>

using namespace std;

long long getLove(int x){
    string s = to_string(x);
    string rvS = "";
    for(auto i:s){
        int k = '9' - i;
        rvS.append(to_string(k));
    }
    long long result = stol(rvS) * x;
    return result;
}

int main(){
    int t;
    string x,mid;
    long long ans;
    cin >> t;
    while(t--){
        cin >> x;
        mid = "1";
        for (auto i: x){
            mid.append("0");
        }
        long long intM = stol(mid)/2;
        int intX = stoi(x);

        if(intM-1>intX){
            cout<<getLove(intX);
        }
        else{
            cout << getLove(intM);
        }
        cout << "\n";
    }
}