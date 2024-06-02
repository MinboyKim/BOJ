#include <iostream>
#include <algorithm>

using namespace std;

int maxX, maxY, minX, minY;
int curX, curY;


pair<int, int> curState = {0, 1};

int main()
{
    int t;
    string str;
    cin >> t;
    while (t--)
    {
        curX = 0;
        curY = 0;
        maxX = 0;
        maxY = 0;
        minX = 0;
        minY = 0;
        cin >> str;

        for (auto c : str)
        {
            if (c == 'F')
            {
                curX += curState.first;
                curY += curState.second;
            }
            if (c == 'B')
            {
                curX -= curState.first;
                curY -= curState.second;
            }
            if (c == 'L')
            {
                if(curState.first){
                    curState.second = curState.first;
                    curState.first = 0;
                }
                else{
                    curState.first = curState.second * -1;
                    curState.second = 0;
                }
            }
            if (c == 'R')
            {
                if (curState.first)
                {
                    curState.second = curState.first*-1;
                    curState.first = 0;
                }
                else
                {
                    curState.first = curState.second;
                    curState.second = 0;
                }
            }
            maxX = max(maxX, curX);
            maxY = max(maxY, curY);
            minX = min(minX, curX);
            minY = min(minY, curY);
        }


        cout << (maxX - minX) * (maxY - minY) << '\n';
    }
}
