#include <bits/stdc++.h>

using namespace std;

int l = 1;
int m = 2;
int r = 3;
int cnt;
vector<pair<int, int>> pii;
void hanoi(int n, int start, int mid, int end) {
    if (n==1){
        pii.push_back({start, end});
        cnt++;
    } else {
        hanoi(n - 1, start, end, mid);
        pii.push_back({start, end});
        cnt++;
        hanoi(n - 1, mid, start, end);
    }
}

int main() {
    int n;
    cin >> n;

    hanoi(n, l,m,r);
    cout << cnt<<'\n';
    for(auto i: pii){
        cout << i.first << " " << i.second<<'\n';
    }
}