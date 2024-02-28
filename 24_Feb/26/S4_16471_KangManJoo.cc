#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    deque<int> a;
    int b[101010];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> k;
        a.push_front(k);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b, b + n);

    int cnt = 0;
    int next;
    for (int i = 0; i < n; i++) {
        next = b[i];
        if (a.front() < next) {
            a.pop_front();
            cnt++;
        } else {
            a.pop_back();
        }
    }
    if( cnt>n/2) cout<<"YES";
    else
        cout << "NO";
}