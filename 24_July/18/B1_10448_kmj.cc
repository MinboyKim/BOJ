#include <bits/stdc++.h>

using namespace std;

int tri(int n){
    return n * (n - 1) / 2;
}

int main(){
    int t,n=0;
    cin >> t;
    while(t--){
        int q;
        cin >> q;
        //1,3,6,10,15,21,28,...
        //1,1+2,1+2+3,1+2+3+4, 1+2+3+4+5
        int flag = 0;
        for (int i = 2; i < 50; i++)
        {
            for (int j = 2; j < 50; j++){
                for (int k = 2; k < 50; k++){
                    if (tri(i) + tri(j) + tri(k) == q){
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag){
            cout << 1;
        }
        else{
            cout << 0;
        }
        cout << '\n';
    }
}