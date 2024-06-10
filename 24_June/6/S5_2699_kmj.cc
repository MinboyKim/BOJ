#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
priority_queue<pair<int, pii>, vector<piii>, greater<piii>> pq;

int main()
{
    int t, r, c, l, curC = 0;
    cin >> t;
    while (t--)
    {
        curC = 0;
        cin >> r >> c;
        for (int i = 0; i <r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> l;
                if (l == -1)
                {
                    continue;
                }
                pq.push({l, {i, j}});
            }
        }

        int time = 0;


        while (!pq.empty())
        {

            piii cur = pq.top();
            pq.pop();
            time += cur.second.first * 2 * 10;
            
            int minR= min(abs(curC-cur.second.second),curC+c-cur.second.second);
            minR = min(minR, abs(c - curC) + cur.second.second);
            time += minR * 5;
            curC = cur.second.second;
        }
        cout << time << "\n";
    }
}