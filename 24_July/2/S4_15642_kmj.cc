#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long tmp,cur=1;
    long pre = 0;
    cin >> n;

    if(n==0||n==1){
        cout << n;
        return 0;
    }
    n -= 1;

    while(n--){
        tmp=cur;
        cur = pre + cur;
        pre = tmp;
        cur %= 1000000007;
        pre %= 1000000007;
    }
    cout << cur;
}