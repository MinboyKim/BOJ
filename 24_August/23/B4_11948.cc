#include <bits/stdc++.h>

using namespace std;

int main(){
    int minX = 101;
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        if(x < minX){
            minX = x;
        }
        sum+=x;
    }
    sum-=minX;

    minX = 101;
    for(int i = 0; i < 2; i++){
        int x;
        cin >> x;
        if(x < minX){
            minX = x;
        }
        sum+=x;
    }
    sum-=minX;
    cout<<sum;
}