#include <cmath>
#include <iostream>

using namespace std;

int N, A, B, M, sumAns, conAns;
int dom[111];
int score[111];
int week[55];

void change(int num) {
  int temp = dom[num];
  dom[num] = dom[num + 1];
  dom[num + 1] = temp;
  score[dom[num]] -= 2;
  score[dom[num + 1]] += 2;
}

void whereRU(int cur) {
  int idH = 0;
  int idJ = 0;
  for (int i = 1; i <= N; i++) {
    if (idH && idJ) break;
    if (dom[i] == 1) idH = i;
    if (dom[i] == A) idJ = i;
  }
  if (abs(idH - idJ) <= B) week[cur] = 1;
}

void solve(int cur) {
  for (int i = 1; i <= N - 1; i++) {
    int flag = false;
    if (score[dom[i]] >= 0 && score[dom[i + 1]] &&
        score[dom[i]] >= score[dom[i + 1]] + 2)
      change(i);
    else if (score[dom[i]] >= 0 && score[dom[i + 1]] < 0)
      continue;
    else if (score[dom[i + 1]] >= 0 && score[dom[i]] < 0)
      change(i);
    else if (score[dom[i]] < 0 && score[dom[i]] < 0 &&
             score[dom[i]] + 4 <= score[dom[i + 1]])
      change(i);
  }
  whereRU(cur);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> A >> B >> M;
  int a;
  for (int i = 1; i <= N; i++) dom[i] = i;
  for (int i = 1; i <= M - 1; i++) {
    solve(i);
    for (int j = 1; j <= N; j++) {
      cin >> score[j];
    }
    for (int j = 1; j <= N; j++) {
      cin >> a;
      score[j] -= a;
    }
  }
  solve(M);

  int temp = 0;
  for (int i = 1; i <= M + 1; i++) {
    if (week[i]) {
      sumAns++;
      temp++;
    }
    if (!week[i]) {
      conAns = max(conAns, temp);
      temp = 0;
    }
  }

  cout << sumAns << " " << conAns << "\n";

  return 0;
}