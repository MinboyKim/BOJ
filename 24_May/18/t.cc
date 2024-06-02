#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            cin >> a;
            if (a == 'w')
            {
                cout << "chunbae";
                return 0;
            }
            else if (a == 'b')
            {
                cout << "nabi";
                return 0;
            }
            else if (a == 'g')
            {
                cout << "yeongcheol";
                return 0;
            }
        }
    }
}