#include <bits/stdc++.h>

using namespace std;

int cube[126][126][126];
vector<tuple<int, int, int>> tp;

int main(){
    int n, m,x,y,z;
    cin >> n >> m;

    int ans = 0;

    while (m--)
    {
        cin >> x >> y >> z;
        cube[x][y][z] = 1;

        tp.push_back({x, y, z});
    }
    
    for(auto v: tp){
        x = get<0>(v);
        y = get<1>(v);
        z = get<2>(v);

        if (cube[x - 1][y][z] && cube[x + 1][y][z] && cube[x][y+1][z] && cube[x][y - 1][z] && cube[x][y][z + 1] && cube[x][y][z - 1]){
            ans++;
        }
    }
    cout << ans;
}