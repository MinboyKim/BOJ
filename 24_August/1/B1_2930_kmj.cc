#include <bits/stdc++.h>

using namespace std;

int r, s, p;
int main()
{
    int t, a;
    cin >> t;
    string str1, str2;
    cin >> str1;
    for (auto i : str1)
    {
        if (i == 'S')
        {
            s++;
        }
        else if (i == 'P')
        {
            p++;
        }
        else
        {
            r++;
        }
    }

    cin >> a;
    int realC = 0, exC = 0;
    int tms, tmr, tmp;
    while (a--)
    {
        tms = s;
        tmr = r;
        tmp = p;
        cin >> str2;
        for (int i = 0; i < str1.size(); i++)
        {
            if (str1[i] == 'S' && str2[i] == 'P')
            {
                realC += 2;
            }
            else if (str1[i] == 'R' && str2[i] == 'S')
            {
                realC += 2;
            }
            else if (str1[i] == 'S' && str2[i] == 'P')
            {
                realC += 2;
            }
            else if (str1[i] == str2[i])
            {
                realC += 1;
            }

            if(str2[i]=='S'){
                if(tmr){
                    tmr--;
                    exC+=2;
                }
                else if(tms){
                    tms--;
                    exC++;
                }
                else{
                    tmp--;
                }
            }
            if (str2[i] == 'R')
            {
                if (tmp)
                {
                    tmp--;
                    exC += 2;
                }
                else if (tmr)
                {
                    tmr--;
                    exC++;
                }
                else
                {
                    tms--;
                }
            }
            if (str2[i] == 'P')
            {
                if (tms)
                {
                    tms--;
                    exC += 2;
                }
                else if (tmp)
                {
                    tmp--;
                    exC++;
                }
                else
                {
                    tmr--;
                }
            }
        }
    }
    cout << realC << '\n'
         << exC;
}