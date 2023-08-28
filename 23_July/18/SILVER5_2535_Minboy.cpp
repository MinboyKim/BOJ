#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
  int country;
  int number;
  int score;
} student;

typedef pair<int, int> pii;

int N;
student Arr[111];
int cnt[111];
vector<pii> ans;

bool compare(student a, student b) { return a.score > b.score; }

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> Arr[i].country >> Arr[i].number >> Arr[i].score;

  sort(Arr, Arr + N, compare);

  int idx = 0;
  while (true) {
    if (ans.size() == 3) break;
    if (cnt[Arr[idx].country] < 2) {
      cnt[Arr[idx].country]++;
      ans.push_back({Arr[idx].country, Arr[idx].number});
    }
    idx++;
  }

  for (auto &i : ans) cout << i.first << " " << i.second << "\n";

  return 0;
}