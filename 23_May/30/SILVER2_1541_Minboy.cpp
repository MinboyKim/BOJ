#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string s;
vector<string> v;
int ans;
int Arr[55];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> s;

  stringstream ss(s);
  string temp;
  while (getline(ss, temp, '-')) v.push_back(temp);

  int id = 0;
  for (auto &i : v) {
    stringstream ss2(i);
    string temp2;
    vector<string> vec;
    while (getline(ss2, temp2, '+')) vec.push_back(temp2);
    for (auto &j : vec) Arr[id] += stoi(j);
    id++;
  }

  ans += Arr[0];
  for (int i = 1; i < 55; i++) ans -= Arr[i];

  cout << ans << "\n";

  return 0;
}