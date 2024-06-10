#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;

    cin >> str;

    for (auto s : str)
    {
        if (s == 'E')
        {
            cout << "I";
        }
        else if (s == 'I')
        {
            cout << "E";
        }
        else if (s == 'S')
        {
            cout << "N";
        }
        else if (s == 'N')
        {
            cout << "S";
        }
        else if (s == 'T')
        {
            cout << "F";
        }
        else if (s == 'F')
        {
            cout << "T";
        }
        else if (s == 'J')
        {
            cout << "P";
        }
        else if (s == 'P')
        {
            cout << "J";
        }
    }
}