#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,n,k,c;
    cin >> t;
    while (t--)
    {
        int cnt = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++){
            cin >> c;
            cnt+=c / k;
        }
        cout << cnt << '\n';
    }
}