#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int Arr[9];
int sum;
vector<int> ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  for (int i = 0; i < 9; i++) {
    cin >> Arr[i];
    sum += Arr[i];
  }

  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (sum - Arr[i] - Arr[j] == 100) {
        for (int k = 0; k < 9; k++) {
          if (k == i || k == j) continue;
          ans.push_back(Arr[k]);
        }
        sort(ans.begin(), ans.end());
        for (auto &i : ans) cout << i << "\n";
        return 0;
      }
    }
  }

  return 0;
}