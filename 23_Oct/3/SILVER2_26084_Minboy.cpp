#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

typedef long long ll;

ll ans = 1, N;
int Arr[30];
string S;
unordered_set<char> mySet;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> S >> N;
    string a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        Arr[a[0] - 'A']++;
    }

    for (int i = 0; i < S.length(); i++) {
        mySet.insert(S[i]);
        ans *= Arr[S[i] - 'A'];
        Arr[S[i] - 'A']--;
    }

    if (mySet.size() == 1)
        ans /= 6;
    else if (mySet.size() == 2)
        ans /= 2;
    cout << ans << "\n";

    return 0;
}