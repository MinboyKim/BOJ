#include <iostream>

using namespace std;

int n, m;
int parent[1'000'000];

int my_find(int n) {
    if (parent[n] == n) return n;
    return parent[n] = my_find(parent[n]);
}

void my_uni(int a, int b) {
    a = my_find(a);
    b = my_find(b);
    if (a == b) return;
    parent[a] = b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);


    int c, a, b;
    cin >> n >> m;
    for(int i = 0;i<n;i++) parent[i] = i;
    for(int i = 0;i<m;i++) {
        cin >> c >> a >> b;
        if (c == 0) my_uni(a, b);
        else {
            if (my_find(a) == my_find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}