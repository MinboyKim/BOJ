#include <bits/stdc++.h>

using namespace std;

int arr[40];
int main() {
    string s;
    char i;
    while ((i = getchar()) != EOF) {
            if(i==' '){
                continue;
            }
            arr[i - 'a']++;
    }
    int max = 0;
    for (int i = 0; i < 30; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (int i = 0; i < 30; i++) {
        if (arr[i] == max) {
            char k = 'a' + i;
            cout << k;
        }
    }
}