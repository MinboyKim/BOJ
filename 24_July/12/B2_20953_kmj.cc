#include <bits/stdc++.h>

using namespace std;
long long dolmen(int a, int b)
{
    long long sum = 0;
    sum = 0;

    long long p = a + b;

 

    sum = p * (p-1) * p / 2;


    return sum;
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << dolmen(a, b) << '\n';
    }
}