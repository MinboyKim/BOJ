#include <bits/stdc++.h>

using namespace std;

set<string> st;

int main(){
    int n;
    char c;
    string input;
    cin >> n>>c;
    while(n--){
        cin >> input;
        st.insert(input);
    }
    if(c=='Y'){
        cout << st.size();
    }
    else if(c=='F'){
        cout << st.size() / 2;
    }
    else{
        cout << st.size() / 3;
    }
}