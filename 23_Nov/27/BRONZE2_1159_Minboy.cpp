#include <iostream>
#include <string>

using namespace std;

int N;
string ans;
char Arr[30];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        Arr[temp[0] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (Arr[i] >= 5) ans += 'a' + i;
    }

    cout << (ans == "" ? "PREDAJA" : ans) << "\n";

    return 0;
}