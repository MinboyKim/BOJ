#include <iostream>
#include <string>

using namespace std;

string s;
int Arr[30];

int main(void) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  cin >> s;
  for (int i = 0; i < s.length(); i++) Arr[s[i] - 'a']++;
  for (int i = 0; i <= 'z' - 'a'; i++) cout << Arr[i] << " ";

  return 0;
}