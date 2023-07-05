#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int parent;
    vector<int> child;
}node;

int N, root, ans;
node tree[55];

void dfs(int n) {
    if (tree[n].child.size() == 0){
        ans++;
        return;
    }

    for(auto&i : tree[n].child) 
        if (tree[i].parent != 99) dfs(i);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    int a;
    for(int i = 0;i<N;i++) {
        cin >> a;
        tree[i].parent = a;
        if (a == -1) {
            root = i;
            continue;
        }
        tree[a].child.push_back(i);
    }

    cin >> a;
    if (a == root) {
        cout << 0 << "\n";
        return 0;
    }
    tree[tree[a].parent].child.erase(
    remove_if(
        tree[tree[a].parent].child.begin(),
        tree[tree[a].parent].child.end(),
        [&a](int child) {
            return child == a;
        }
    ),tree[tree[a].parent].child.end());
    tree[a].parent = 99;
    dfs(root);

    cout << ans << "\n";

    return 0;
}