#include <iostream>
#include <set>
#include <string>

using namespace std;

int N, M, Q;
int ptr[200'020];
set<int> ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> M >> Q;
  for (int i = 1; i <= M; i++) cin >> ptr[i];

  string s;
  int a, b, temp;
  for (int i = 0; i < Q; i++) {
    cin >> s;
    if (s == "assign") {
      cin >> a >> b;
      ptr[a] = ptr[b];
    } else if (s == "swap") {
      cin >> a >> b;
      temp = ptr[a];
      ptr[a] = ptr[b];
      ptr[b] = temp;
    } else {
      cin >> a;
      ptr[a] = 0;
    }
  }

  for (int i = 1; i <= M; i++)
    if (ptr[i]) ans.insert(ptr[i]);

  cout << ans.size() << "\n";
  for (auto &i : ans) cout << i << "\n";

  return 0;
}