#include <bits/stdc++.h>

using namespace std;

int cow[101];
int main()
{
    int n, a, b;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cow[i] = -1;
    }
    int cnt = 0;

    while (n--)
    {
        cin >> a >> b;
        if(cow[a]==b){
            continue;
        }
        else if(cow[a]==-1){
            cow[a] = b;
        }
        else{
            cow[a] = b;
            cnt++;
        }
    }

    cout << cnt;
}