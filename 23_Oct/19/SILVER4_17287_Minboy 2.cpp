#include <iostream>
#include <string>

using namespace std;

string s;
int ans, sum;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case '(':
            sum += 1;
            break;
        case '{':
            sum += 2;
            break;
        case '[':
            sum += 3;
            break;
        case ')':
            sum -= 1;
            break;
        case '}':
            sum -= 2;
            break;
        case ']':
            sum -= 3;
            break;
        default:
            ans = max(ans, sum);
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}