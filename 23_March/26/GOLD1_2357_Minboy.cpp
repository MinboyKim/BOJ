#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int Arr[101'010];
int minTree[404'040];
int maxTree[404'040];

int initMin(int node, int start, int end) {
  if (start == end) return minTree[node] = Arr[start];
  int mid = (start + end) / 2;
  return minTree[node] = min(initMin(node * 2, start, mid),
                             initMin(node * 2 + 1, mid + 1, end));
}

int initMax(int node, int start, int end) {
  if (start == end) return maxTree[node] = Arr[start];
  int mid = (start + end) / 2;
  return maxTree[node] = max(initMax(node * 2, start, mid),
                             initMax(node * 2 + 1, mid + 1, end));
}

int minVal(int node, int start, int end, int left, int right) {
  if (left > end || right < start) return 2'000'000'000;
  if (left <= start && right >= end) return minTree[node];
  int mid = (start + end) / 2;
  return min(minVal(node * 2, start, mid, left, right),
             minVal(node * 2 + 1, mid + 1, end, left, right));
}

int maxVal(int node, int start, int end, int left, int right) {
  if (left > end || right < start) return 0;
  if (left <= start && right >= end) return maxTree[node];
  int mid = (start + end) / 2;
  return max(maxVal(node * 2, start, mid, left, right),
             maxVal(node * 2 + 1, mid + 1, end, left, right));
}

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int a, b;
  cin >> N >> M;

  for (int i = 0; i < N; i++) cin >> Arr[i];
  initMin(1, 0, N - 1);
  initMax(1, 0, N - 1);

  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    cout << minVal(1, 0, N - 1, a - 1, b - 1) << " "
         << maxVal(1, 0, N - 1, a - 1, b - 1) << "\n";
  }

  return 0;
}