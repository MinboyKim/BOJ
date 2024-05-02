#include <bits/stdc++.h>

using namespace std;

string arr[8] = {"000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010"};

int main()
{
    int n;
    string str;
    cin >> n;
    cin >> str;

    int cnt = 0;
    string q = "";
    string ans = "";

    for (auto s : str)
    {
        
        int flag = 0;
        cnt++;
        q += s;
        if (cnt % 6==0)
        {
            for (int j = 0; j < 8; j++)
            {
                int ct = 0;
                for (int i = 0; i < 6; i++)
                {
                    if (q[i] != arr[j][i])
                    {
                        ct++;
                        if (ct > 1)
                        {
                            break;
                        }
                    };
                }
                if (ct <= 1)
                {
                    char ch = 'A' + j;
                    ans += ch;
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                cout << cnt/6;
                exit(0);
            }
            q = "";
        }
    }
    cout << ans;
}