#include <algorithm>
#include <iostream>
#define PIV 1 << 20

using namespace std;

int tree[PIV << 1];
int N, M, a, b;

void update(int pos, int val) {
  pos |= PIV;
  tree[pos] = val;
  while (pos >>= 1) tree[pos] = min(tree[pos << 1], tree[pos << 1 | 1]);
}

int query(int l, int r) {
  l |= PIV, r |= PIV;
  int ret = 1'999'999'999;
  while (l <= r) {
    if (l & 1) ret = min(ret, tree[l++]);
    if (~r & 1) ret = min(ret, tree[r--]);
    l >>= 1, r >>= 1;
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> a;
    update(i, a);
  }

  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << query(a, b) << "\n";
  }

  return 0;
}