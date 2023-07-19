#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pll;
long long n, k;
multiset<long long> bag;

struct cmp{
  bool operator()(const pll& a, const pll& b) const
  { 
    return a.second > b.second; 
  }  
};

 multiset<pll, cmp> gem;

int main() {

  cin >> n >> k;
  long long m, v, c;
  while (n--) {
    cin >> m >> v;
    gem.insert({m, v});
  }
  for (int i = 0; i < k; i++) {
    cin >> c;
    bag.insert(c);
  }


  long long result = 0;

  for (auto i : gem) {
    auto t = bag.lower_bound(i.first);
    if (t != bag.end()) {
      bag.erase(t);
      result += i.second;
    }
  }
  cout << result;
}