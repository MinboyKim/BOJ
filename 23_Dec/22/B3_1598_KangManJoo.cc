#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    int remainA = a%4;
    int remainB = b%4;
    if(remainA ==0) remainA = 4;
    if(remainB == 0) remainB=4;
    cnt += abs(remainA - remainB);
    cnt += abs(a / 4 - b / 4);
    if (a < b) {
        if (a % 4 == 0) {
            cnt++;
        }
        if (b % 4 == 0) {
            cnt--;
        }
    } else if (a > b) {
        if (a % 4 == 0) {
            cnt--;
        }
        if (b % 4 == 0) {
            cnt++;
        }
    }
    cout<<cnt;

}