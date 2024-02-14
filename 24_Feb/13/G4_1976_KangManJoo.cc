#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

int uf[1010];

int findUnion(int x) {
    if (uf[x] == x) {
        return x;
    } else {
        return findUnion(uf[x]);
    }
}

int makeSameUnion(int x, int t) {
    if (uf[x] == x) {
        return x;
    } else {
        int nextU = uf[x];
        uf[x] = t;
        return makeSameUnion(nextU, t);
    }
}

void makeUnion(int a, int b) {
    int groupA = findUnion(a);
    if (groupA == findUnion(b)) {
        return;
    }

    b = makeSameUnion(b, groupA);
    uf[b] = groupA;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, nextCity, bridge;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        uf[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> bridge;
            if (i == j)
                continue;

            if (bridge == 1) {
                makeUnion(i, j);
            }
        }
    }

    int startUnion, start;
    cin >> start;
    startUnion = findUnion(start);
    int flag = 0;

    for (int i = 1; i < m; i++) {
        cin >> nextCity;
        if (startUnion != findUnion(nextCity)) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        cout << "NO";
    } else
        cout << "YES";
}