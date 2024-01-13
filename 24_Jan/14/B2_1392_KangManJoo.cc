#include <bits/stdc++.h>

using namespace std;

int arr[101];
int qarr[1001];
int mm[10010];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int curt = arr[i];
        for (int j = 0; j < curt; j++) {
            mm[cur] = i+1;
            cur++;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> qarr[i];
        cout << mm[qarr[i]] << '\n';
    }
}