#include <bits/stdc++.h>

using namespace std;

char arr[10100][10100];

int main(){
    int t;
    cin >> t;
    string str;

    while(t--)
    {
        cin >> str;
        int size = str.size();
        int len = sqrt(size);
        for (int i = 0; i < len; i++){
            for (int j = 0; j < len; j++){
                arr[i][j] = str[i * len + j];
            }
        }

        for (int i = len - 1; i >= 0; i--){
            for (int j = 0; j < len; j++){
                cout << arr[j][i];
            }
        }
        cout << '\n';
    }
}