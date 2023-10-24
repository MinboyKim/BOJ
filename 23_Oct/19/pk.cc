#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> v;
map<pair<long long, long long>, long long> map1;
long long maxi = 1;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    v.resize(N);
    for (auto &a : v)
        cin >> a.first >> a.second;
    sort(v.begin(), v.end());
    for (auto a : v)
        map1.insert({make_pair(a.first * 2, a.second * 2), 1});

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int x = v[i].first + v[j].first;
            int y = v[i].second + v[j].second;
            auto a = map1.find({x, y});
            if (a != map1.end()) {
                a->second += 2;
                maxi = max(maxi, a->second);
            } else {
                map1.insert({make_pair(x, y), 2});
                maxi = max(maxi, (long long)2);
            }
        }
    }
    cout << maxi;
}