#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string s;
vector<int> v;

void split(char del) {
    istringstream iss(s);
    string buffer;

    while (getline(iss, buffer, del))
        v.push_back(stoi(buffer));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> s;

    split('/');

    cout << (v[0] + v[2] < v[1] || v[1] == 0 ? "hasu" : "gosu") << "\n";

    return 0;
}