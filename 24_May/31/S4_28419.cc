#include <bits/stdc++.h>

using namespace std;

long long odd, even;
int main()
{
    int n,cur;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> cur;
        if (i % 2 == 0)
        {
            odd += cur;
        }
        else{
            even += cur;
        }
    }
    if(n==3){
        if(odd>even){
            cout << -1;
            exit(0);
        }
    }

    cout << abs(odd - even);
}