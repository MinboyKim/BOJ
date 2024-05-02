#include <bits/stdc++.h>

using namespace std;

int team[11];
int main() {
    int n, s, r,br;
    cin >> n >> s >> r;

    for (int i = 1; i <= n; i++){
        team[i] = 1;
    }
    for (int i = 0; i < s; i++){
        cin >> br;
        team[br]--;
    }
    while(r--){
        cin >> br;
        team[br]++;
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++){
        if(team[i]){
            team[i]--;
        }
        else if(team[i-1]){
            team[i - 1]--;
        }
        else if(team[i+1]>=2){
            team[i + 1]--;
        }
        else{
            cnt++;
        }
    }
    cout << cnt;
}