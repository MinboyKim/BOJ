#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int main()
{
    string str;
    string cmd = "";
    while (cin >> str)
    {
        cmd += str;
        if(str=="00"){
            break;
        }
    }

    istringstream ss(cmd);

    string buffer;
    vector<string> v;

    while (getline(ss, buffer, ','))
    {
        v.push_back(buffer);
    }

    long long result = 0;

    for(auto i: v){
        result += stoi(i);
    }

    cout << result;
}