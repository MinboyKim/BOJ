#include <bits/stdc++.h>

using namespace std;

int arr[7];
int avail[7];

int main()
{
    int n;
    cin >> n;
    int work;

    while (n--)
    {
        cin >> work;
        work %= 7;
        arr[work]++;
    }

    avail[0] = 1;

    for (int i = 1; i < 7; i++)
    {
        while(arr[i]--){
            vector<int> v;
            for (int j = 6; j >= 0; j--)
            {
                if(avail[j]){
                    v.push_back(j);
                }
            }
            for(auto j : v){
                avail[(j + i) % 7] = 1;
            }
        }
    }


    if (avail[4])
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}