#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef tuple<ll,ll,ll> tiii;

vector<tiii> tps;
vector<tiii> ans;

int main() {
    ll n, s, e, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> e >> c;
        tiii tp(s, e, c);
        tps.push_back(tp);
    }

    sort(tps.begin(), tps.end());

    ll end = 0, curEnd, curCost, curStart = -1;

    for (int i = 0; i < n - 1; i++) {
        tiii next = tps[i + 1];

        if (curStart < 0) {
            curStart = get<0>(tps[i]);
            curEnd = get<1>(tps[i]);
            curCost = get<2>(tps[i]);
        }

        if (curEnd >= get<0>(next)) {
            curEnd = max(curEnd,get<1>(next));
            curCost = min(curCost, get<2>(next));

            if (i == n - 2) {
                tiii newLoad(curStart, curEnd, curCost);
                ans.push_back(newLoad);
            }
        } else {
            tiii newLoad(curStart, curEnd, curCost);
            ans.push_back(newLoad);
            curStart = -1;
            if (i == n - 2) {
                tiii newLoad(get<0>(next), get<1>(next), get<2>(next));
                ans.push_back(newLoad);
            }
        }
    }

    if(n==1){
        ans.push_back(tps[0]);
    }

    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << '\n';
    }
}