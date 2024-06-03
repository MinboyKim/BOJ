#include <iostream>
#include <string>

using namespace std;

int T, N;
char Arr[1111];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> Arr[i];
        string s = "";
        s += Arr[0];
        for (int i = 1; i < N; i++) {
            if (s[0] >= Arr[i])
                s = Arr[i] + s;
            else
                s = s + Arr[i];
        }
        cout << s << "\n";
    }

    return 0;
}