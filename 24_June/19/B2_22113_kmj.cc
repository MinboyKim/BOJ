#include <bits/stdc++.h>

using namespace std;

int bus[101][101];
vector<int> v;

int main(){
    int n, m,num;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> num;
        v.push_back(num);
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> bus[i][j];
        }
    }

    int cnt = 0;
    int pre = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        int next = v[i];
        cnt += bus[pre][next];
        pre = next;
    }
    cout << cnt;
}