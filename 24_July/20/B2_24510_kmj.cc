#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string str;
    string word;
    vector<string> v;
    cin >> n;
    int MaxC=0;
    while (n--)
    {
        int count = 0;         
        cin >> str;
        for (int i = 0; i < str.size(); i++)
        {
            if(str[i]=='w'){
                if(str.size()-i<4){
                    continue;
                }
                if (str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i+4]=='e'){
                    count++;
                    i += 4;
                    continue;
                }
            }
            if(str[i]=='f'){
                if(str.size()-i<2){
                    continue;
                }
                if (str[i + 1] == 'o' && str[i + 2] == 'r'){
                    count++;
                    i += 2;
                    continue;
                }
            }
        }
        if(count>MaxC){
            MaxC = count;
        }
    }
    cout << MaxC;
}