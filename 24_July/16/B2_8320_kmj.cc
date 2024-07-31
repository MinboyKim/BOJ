#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int cnt = 0;
    cnt += n;
    for (int i = 2; i <= n / 2; i++){
        int k = n / i - i+1;
        if(k<0){
            break;
        }
        cnt += k;
    }
    cout << cnt;
}