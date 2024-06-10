#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef pair<int, int> pii;

map<string, pii> m;
long long ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    m.insert({"black", {0, 1}});
    m.insert({"brown", {1, 10}});
    m.insert({"red", {2, 100}});
    m.insert({"orange", {3, 1000}});
    m.insert({"yellow", {4, 10000}});
    m.insert({"green", {5, 100000}});
    m.insert({"blue", {6, 1000000}});
    m.insert({"violet", {7, 10000000}});
    m.insert({"grey", {8, 100000000}});
    m.insert({"white", {9, 1000000000}});

    string s;
    cin >> s;
    ans += m[s].first * 10;
    cin >> s;
    ans += m[s].first;
    cin >> s;
    ans *= m[s].second;

    cout << ans << "\n";

    return 0;
}