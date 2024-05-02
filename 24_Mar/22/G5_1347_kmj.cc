#include <bits/stdc++.h>

using namespace std;

int n;
int a, s, e;
typedef pair<int, int> pii;
pii arr[101010];

struct cmp {
    bool operator()(pii a, pii b) { return a.second > b.second; }
};

priority_queue<pii, vector<pii>, cmp> pq;

bool cmt(pii a, pii b) { return a.first < b.first; }

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> s >> e;
        
        arr[i] = {s, e};
    }

    sort(arr, arr + n, cmt);


    pq.push(arr[0]);
    for (int i = 1; i < n; i++){
        if(pq.top().second<=arr[i].first){
            pq.pop();
            pq.push({arr[i].first, arr[i].second});
        } else {
            pq.push(arr[i]);
        }
    }
    cout << pq.size();
}