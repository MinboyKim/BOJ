#include <bits/stdc++.h>

using namespace std;

long long height[303030];

int maxH = 0;

int main(){
    int n, d;
    cin >> n >> d;
    int h;

    while(n--){
        cin >> h;
        height[h]++;

        if(maxH<h){
            maxH = h;
        }
    }

    long long ans = 0;
    while (d--)
    {
        ans += height[maxH];
        maxH--;
        height[maxH] += height[maxH+1];
        if(maxH==0){
            break;
        }
    }
    cout << ans;
}