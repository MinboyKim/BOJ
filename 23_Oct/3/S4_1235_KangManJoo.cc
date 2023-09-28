#include <bits/stdc++.h>

using namespace std;


int n;
set<string> students;


int main() {
    cin >> n;
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        students.insert(s);
    }
    int cnt=1;
    while(true){
        set<string> eq;
        for(auto i : students){
            eq.insert(i.substr(cnt));
        }
        if(eq.size()!=students.size())
            break;
        cnt++;
    }
    cout<<s.length()-(cnt-1);
}