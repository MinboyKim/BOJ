#include <bits/stdc++.h>

using namespace std;

set<string> stt;

int main()
{
    int n;
    string str;
    cin >> n;
    while(n--){
        cin >> str;
        sort(str.begin(),str.end());
        stt.insert(str);
    }
    cout << stt.size();
}