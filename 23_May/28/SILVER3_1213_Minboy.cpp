#include <iostream>
#include <string>

using namespace std;

int cnt[30], odd;
string s, ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> s;
  for (int i = 0; i < s.length(); i++) cnt[s[i] - 'A']++;

  for (int i = 0; i < 26; i++)
    if (cnt[i] % 2 == 1) odd++;

  if (odd > 1) {
    cout << "I'm Sorry Hansoo\n";
    return 0;
  }

  for (int i = 0; i < 26; i++)
    for (int j = 0; j < cnt[i] / 2; j++) ans += i + 'A';

  for (int i = 0; i < 26; i++)
    if (cnt[i] % 2 == 1) ans += i + 'A';

  for (int i = 25; i >= 0; i--)
    for (int j = 0; j < cnt[i] / 2; j++) ans += i + 'A';

  cout << ans << "\n";

  return 0;
}