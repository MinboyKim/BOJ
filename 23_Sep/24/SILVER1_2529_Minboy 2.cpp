#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k;
string compare;
vector<string> ans;
int Visit[10];

bool check(int d, string msg) {
  for (int i = 0; i < d; i++) {
    if ((compare[i] == '>' && msg[i] < msg[i + 1]) ||
        (compare[i] == '<' && msg[i] > msg[i + 1]))
      return false;
  }
  return true;
}

void dfs(int d, string msg) {
  if (d == k + 1) {
    ans.push_back(msg);
    return;
  }
  for (int i = 0; i < 10; i++) {
    if (Visit[i]) continue;
    msg.push_back(i + '0');
    Visit[i] = 1;
    if (check(d, msg)) dfs(d + 1, msg);
    msg.pop_back();
    Visit[i] = 0;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> k;
  string s;
  for (int i = 0; i < k; i++) {
    cin >> s;
    compare += s;
  }

  dfs(0, "");

  sort(ans.begin(), ans.end(), greater<string>());
  cout << ans[0] << "\n" << ans[ans.size() - 1];

  return 0;
}