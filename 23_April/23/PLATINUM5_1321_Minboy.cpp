#include <iostream>

using namespace std;

int N, M;
int Arr[505'050];
int Tree[2'020'202];

int init(int node, int start, int end) {
  if (start == end) return Tree[node] = Arr[start];
  int mid = (start + end) / 2;
  return Tree[node] =
             init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

int find_sol(int node, int start, int end, int idx) {
  if (start == end) return start;
  int mid = (start + end) / 2;
  if (idx <= Tree[node * 2])
    return find_sol(node * 2, start, mid, idx);
  else
    return find_sol(node * 2 + 1, mid + 1, end, idx - Tree[node * 2]);
}

void update(int node, int start, int end, int idx, int diff) {
  if (idx < start || idx > end) return;
  Tree[node] += diff;
  if (start == end) return;
  int mid = (start + end) / 2;
  update(node * 2, start, mid, idx, diff);
  update(node * 2 + 1, mid + 1, end, idx, diff);
}

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> Arr[i];
  init(1, 0, N - 1);
  cin >> M;
  int Q, I, C;
  for (int i = 0; i < M; i++) {
    cin >> Q;
    if (Q == 1) {
      cin >> I >> C;
      Arr[I] += C;
      update(1, 0, N - 1, I - 1, C);
    } else {
      cin >> I;
      cout << find_sol(1, 0, N - 1, I) + 1 << "\n";
    }
  }

  return 0;
}