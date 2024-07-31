#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int col = n * 5;
    int row = n * 5;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (((i >= n * 3 && i < n * 4) || i < (n * 2)) && j >= n && j < n * 4)
            {
                cout << " ";
            }
            else
            {
                cout << "@";
            }
        }
        cout << endl;
    }
}