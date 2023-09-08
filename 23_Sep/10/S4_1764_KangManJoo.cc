#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;
vector<string> v;

int main() {
    int n, m;
    string s;
    cin >> n >> m;
    while (n--) {
        cin >> s;
        mp.insert({s, 1});
    }
    while (m--) {
        cin >> s;
        if (mp[s] == 1) {
            v.push_back(s);
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (auto i : v) {
        cout << i << '\n';
    }
}