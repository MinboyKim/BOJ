#include <bits/stdc++.h>

using namespace std;

int arr[31];

int main(){
    int t;
    cin >> t;
    while(t--){
        int ans = 0;
        vector<int> v[10];
        int cost[10];
        for (int i = 0; i < 31; i++)
        {
            arr[i] = 0;
        }
        int a, b;
        cin >> a >> b;
        for (int i = 0; i < a; i++){
            int costC;
            int x;
            cin >> x;
            while(x--){
                int y;
                cin >> y;
                v[i].push_back(y);
            }
            cin >> costC;
            cost[i] = costC;
        }
        for (int i = 1; i <= b; i++){
            int x;
            arr[i]=x;
            cin >> x;
        }
        for (int i = 0; i < a; i++){

            int minC = 999;
            for (auto k : v[i])
            {
                minC = min(minC, arr[k]);
            }
            ans+=minC*cost[i];
        }
        cout << ans << '\n';
    }
}