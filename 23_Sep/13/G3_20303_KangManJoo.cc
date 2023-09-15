#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int group[30303];
int n, m, k;
int cost[30303];
pii newGroup[30303];
int visited[30303];
int dp[3033];

int findUnion(int x) {
    if (group[x] == x)
        return x;
    else
        return findUnion(group[x]);
}

void makeUnion(int a, int b) {
    a = findUnion(a);
    b = findUnion(b);
    if (a<b) {
        group[b] = a;
    }
    else{
        group[a]=b;
    }
}


int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        group[i] = i;
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        makeUnion(a, b);
    }

    for (int i = 1; i <= n; i++) {
        int parent = findUnion(i);
        newGroup[parent].first+=cost[i];
        newGroup[parent].second+=1;
    }


    // 여기서부터 배낭 문제 최대 k-1의 무게 까지 계산
    for (int i = 1; i <= n; i++) {
        if(!newGroup[i].first) continue;
        int curCost = newGroup[i].first;
        int curSize = newGroup[i].second;
        for (int j = k; j >=1; j--) {
            if (curSize > j){
                continue;
            }
            dp[j] = max(dp[j], dp[j - curSize] + curCost);
        }
    }

    cout << dp[k-1];
}