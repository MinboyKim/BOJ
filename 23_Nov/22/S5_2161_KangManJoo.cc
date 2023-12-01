#include <bits/stdc++.h>

using namespace std;

deque<int> arr;

int main() {
    int n, k;
    cin >> n;

    for (int i = 0; i < n; i++) {
        arr.push_back(i+1);
    }


    while (true) {
        cout<<arr.front()<<' ';
        arr.pop_front();
        if(arr.empty()) break;
        arr.push_back(arr.front());
        arr.pop_front();
    }
}
