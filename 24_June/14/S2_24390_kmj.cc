#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;

    istringstream ss(str);

    string buffer;
    vector<string> time;

    while (getline(ss, buffer, ':'))
    {
        time.push_back(buffer);
    }

    int h = stoi(time[0]);
    int m = stoi(time[1]);

    m += h * 60;

    int cnt = 0;

    cnt += m / 600;
    m %= 600;
    if (m == 0)
    {
        cout << cnt + 1;
        return 0;
    }
    cnt += m / 60;
    m %= 60;
    if (m == 0)
    {
        cout << cnt + 1;
        return 0;
    }
    int start = 0;
    if ((m / 30) != 0)
    {
        start = 1;
    }
    cnt += m / 30;
    m %= 30;
    if (m == 0)
    {
        cout << cnt;
        return 0;
    }
    cnt += m / 10;
    if (start)
    {
        cout << cnt;
    }
    else
    {
        cout << cnt + 1;
    }
}