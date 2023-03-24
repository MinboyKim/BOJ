#include <iostream>

using namespace std;

int N, M, K;
long long tree[4'040'404];
long long Arr[1'010'101];

long long init(int node, int start, int end) {
  if (start == end) return tree[node] = Arr[start];
  int mid = (start + end) / 2;
  return tree[node] =
             init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

long long sum(int node, int start, int end, int left, int right) {
  if (left > end || right < start) return 0;
  if (left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, left, right) +
         sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, long long diff) {
  if (idx < start || idx > end) return;
  tree[node] += diff;
  if (start == end) return;
  int mid = (start + end) / 2;
  update(node * 2, start, mid, idx, diff);
  update(node * 2 + 1, mid + 1, end, idx, diff);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) cin >> Arr[i];

  init(1, 0, N - 1);

  long long a, b, c;
  for (int i = 0; i < M + K; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      long long diff = c - Arr[b - 1];
      Arr[b - 1] = c;
      update(1, 0, N - 1, b - 1, diff);
    } else if (a == 2)
      cout << sum(1, 0, N - 1, b - 1, c - 1) << "\n";
  }

  return 0;
}