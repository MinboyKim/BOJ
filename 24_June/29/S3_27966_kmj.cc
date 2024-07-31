#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long cnt = 0;
    cnt += n - 1;
    long long t = ((n - 2)*(n - 1));
    cnt += t;

    cout << cnt<<'\n';
    for (int i = 2; i <=n; i++){
        cout<<"1 "<<i<<'\n';
    }
}