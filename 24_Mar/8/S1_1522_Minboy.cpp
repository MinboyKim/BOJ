#include <iostream>
#include <string>

using namespace std;

string s;
int max_b, ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'b') {
            int temp = 1;
            int j = i + 1;
            i++;
            while (j < s.length() && s[j] == 'b') {
                j++;
                i++;
                temp++;
            }
            max_b = max(max_b, temp);
        }
    }

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'b') {
            int temp = 1;
            int j = i + 1;
            i++;
            while (j < s.length() && s[j] == 'b') {
                j++;
                i++;
                temp++;
            }
            if (temp != max_b) ans += temp;
        }
    }

    cout << ans << "\n";

    return 0;
}