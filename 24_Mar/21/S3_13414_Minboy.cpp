#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<string, int> psi;

unordered_map<string, int> m;
string Arr[505'050];
int K, L;
vector<psi> v;

bool compare(psi a, psi b) {
    return a.second < b.second;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> K >> L;
    for (int i = 0; i < L; i++) {
        cin >> Arr[i];
        m[Arr[i]] = i;
    }

    for (auto &i : m)
        v.push_back(i);

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < min(K, (int)v.size()); i++) {
        cout << v[i].first << "\n";
    }

    return 0;
}