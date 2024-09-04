#include <bits/stdc++.h>

using namespace std;

int arr[101];

int main(){
    int t;
    cin >> t;
    while(t--){
        int cnt = 0;
        int n, m;
        cin >> n >> m;
        string s1, s2;
        for (int i = 0; i < m; i++){
            int x;
            cin >> x;
            s1 += to_string(x);
        }
        for (int i = 0; i < m; i++){
            int x;
            cin >> x;
            s2 += to_string(x);
        }
        int x, y;
        x=stoi(s1);
        y=stoi(s2);

        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        string s;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++){
                s += to_string(arr[(i+j)%n]);
            }
            int z = stoi(s);
            if(z>=x && z<=y){
                cnt++;
            }
            s="";
        }
        cout << cnt << '\n';
    }

}