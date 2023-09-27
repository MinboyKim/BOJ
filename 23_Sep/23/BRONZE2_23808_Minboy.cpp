#include <iostream>
#include <string>

using namespace std;

int N;

void solve1() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) cout << "@";
    for (int j = 0; j < N * 3; j++) cout << " ";
    for (int j = 0; j < N; j++) cout << "@";
    cout << "\n";
  }
}

void solve2() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N * 5; j++) cout << "@";
    cout << "\n";
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  solve1();
  solve1();
  solve2();
  solve1();
  solve2();

  return 0;
}