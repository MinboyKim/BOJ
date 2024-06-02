#include <bits/stdc++.h>

using namespace std;

int main()
{
    int flag = 0;
    string str;
    for (int i = 1; i <= 5; i++)
    {
        cin >> str;
        size_t found = str.find("FBI");
        if (found != string::npos)
        {
            cout << i << " ";
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "HE GOT AWAY!";
    }
}