#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii> v;

int main()
{
    int w, h, n, a, b;
    cin >> w >> h >> n;
    while (n--)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }

    int tx, ty;
    int curx = 1, cury = 1;

    int cnt = 0;
    for (auto i : v)
    {
        tx = i.first;
        ty = i.second;

        int movex = tx - curx;
        int movey = ty - cury;

        if(movex * movey > 0)
            cnt += max(abs(movex), abs(movey));
        else{
            cnt += abs(movex) + abs(movey);
        }

        curx = tx;
        cury = ty;
    }
    
    cout << cnt;
}