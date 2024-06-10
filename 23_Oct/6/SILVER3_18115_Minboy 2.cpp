#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N;
vector<int> v;
deque<int> ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        if (v[N - i] == 1)
            ans.push_back(i);
        else if (v[N - i] == 2) {
            int temp = ans.back();
            ans.pop_back();
            ans.push_back(i);
            ans.push_back(temp);
        } else
            ans.push_front(i);
    }

    for (int i = N - 1; i >= 0; i--)
        cout << ans[i] << " ";

    return 0;
}