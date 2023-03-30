#include <iostream>

using namespace std;

typedef long long ll;

ll N, Q;
ll Arr[101'010];
ll tree[404'040];

ll init(int node, int start, int end) {
  if (start == end) return tree[node] = Arr[start];
  int mid = (start + end) / 2;
  return tree[node] =
             init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

ll sum(int node, int start, int end, int left, int right) {
  if (left > end || right < start) return 0;
  if (left <= start && right >= end) return tree[node];
  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, left, right) +
         sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, ll diff) {
  if (idx < start || idx > end) return;
  tree[node] += diff;
  if (start == end) return;
  int mid = (start + end) / 2;
  update(node * 2, start, mid, idx, diff);
  update(node * 2 + 1, mid + 1, end, idx, diff);
}

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N >> Q;
  for (int i = 0; i < N; i++) cin >> Arr[i];
  init(1, 0, N - 1);
  int x, y, a, b;
  for (int i = 0; i < Q; i++) {
    cin >> x >> y >> a >> b;
    if (x > y)
      cout << sum(1, 0, N - 1, y - 1, x - 1) << "\n";
    else
      cout << sum(1, 0, N - 1, x - 1, y - 1) << "\n";
    ll diff = b - Arr[a - 1];
    Arr[a - 1] = b;
    update(1, 0, N - 1, a - 1, diff);
  }

  return 0;
}