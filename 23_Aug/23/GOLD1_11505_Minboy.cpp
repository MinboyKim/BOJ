#include <algorithm>
#include <iostream>
#define PIV 1 << 20
#define MOD 1'000'000'007

using namespace std;

typedef long long ll;

int N, M, K;
ll tree[PIV << 1];

void update(int pos, ll val) {
  pos |= PIV;
  tree[pos] = val;
  while (pos >>= 1) tree[pos] = (tree[pos << 1] * tree[pos << 1 | 1]) % MOD;
}

ll query(int l, int r) {
  l |= PIV;
  r |= PIV;
  ll ret = 1;
  while (l <= r) {
    if (l & 1) ret = (tree[l++] * ret) % MOD;
    if (~r & 1) ret = (ret * tree[r--]) % MOD;
    l >>= 1;
    r >>= 1;
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M >> K;

  ll t;
  for (int i = 1; i <= N; i++) {
    cin >> t;
    update(i, t);
  }

  ll a, b, c;
  for (int i = 0; i < M + K; i++) {
    cin >> a >> b >> c;
    if (a == 1)
      update(b, c);
    else {
      if (b > c) swap(b, c);
      cout << query(b, c) << "\n";
    }
  }

  return 0;
}