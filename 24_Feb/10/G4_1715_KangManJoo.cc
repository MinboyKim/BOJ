#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
priority_queue < ll, vector<ll>, greater < ll >> pq;

int main() {
    int n, card;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> card;
        pq.push(card);
    }

    ll n1,n2;
    ll cnt = 0;
    while (pq.size() > 1) {
        n1 = pq.top();
        pq.pop();
        n2 = pq.top();
        pq.pop();
        cnt += n1 + n2;
        pq.push(n1 + n2);
    }
    cout << cnt;
}