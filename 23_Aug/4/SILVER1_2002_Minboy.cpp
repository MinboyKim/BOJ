#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int N, ans;
string Arr[1111];
string s;
unordered_map<string, int> m;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> s;
    m[s] = i;
  }

  for (int i = 0; i < N; i++) cin >> Arr[i];

  for (int i = 0; i < N - 1; i++)
    for (int j = i + 1; j < N; j++)
      if (m[Arr[i]] > m[Arr[j]]) {
        ans++;
        break;
      }

  cout << ans << "\n";

  return 0;
}
