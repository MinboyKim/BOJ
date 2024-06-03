#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s;
int T, ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (true) {
        ans = 0;
        cin >> s;
        if (s[0] == '-') return 0;

        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            if (!stk.empty() && stk.top() == '{' && s[i] == '}')
                stk.pop();
            else
                stk.push(s[i]);
        }

        while (!stk.empty()) {
            char temp1 = stk.top();
            stk.pop();
            char temp2 = stk.top();
            stk.pop();
            if (temp1 == temp2)
                ans++;
            else
                ans += 2;
        }
        cout << T + 1 << ". " << ans << "\n";
        T++;
    }

    return 0;
}