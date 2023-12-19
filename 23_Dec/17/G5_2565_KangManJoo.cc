#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
vector<pii> arr;
int n, loc,eLoc;
int lis[501];
int len;

int binary_search(int x) {
    int left = 1;
    int right = len;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (lis[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return right;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> loc;
        cin >> eLoc;
        arr.push_back({loc,eLoc});
    }

    sort(arr.begin(),arr.end());

   for(auto i : arr) {
        if (i.second == 0)
            continue;
        if (i.second > lis[len]) {
            len++;
            lis[len] = i.second;
        } else {
            int idx = binary_search(i.second);
            lis[idx] = i.second;
        }
    }
    if(n==0){
        cout<<0;
    }
    else{
        cout << n - len;
    }
}