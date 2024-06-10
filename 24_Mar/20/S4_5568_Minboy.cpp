#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

vector<int> v;
int n, k;
unordered_set<string> s;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    do {
        string temp;
        for (int i = 0; i < k; i++)
            temp += to_string(v[i]);
        s.insert(temp);
    } while (next_permutation(v.begin(), v.end()));

    cout << s.size() << "\n";

    return 0;
}