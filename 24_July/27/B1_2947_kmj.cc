#include <bits/stdc++.h>

using namespace std;

int a[5];
int main()
{
    int tmp;

    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }

    int flag = 0;
    for (int i = 0; i < 5; i++)
    {
        flag = 0;
        for (int j = 0; j < 4; j++)
        {
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                flag = 1;
                for (int k = 0; k < 5; k++)
                {
                    cout << a[k] << " ";
                }
                cout << '\n';
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}