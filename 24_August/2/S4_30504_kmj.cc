#include <bits/stdc++.h>

using namespace std;

int arr[200200];
multiset<int> gold;
vector<int> ans;
int main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    int t, g;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < t; i++)
    {
        cin >> g;
        gold.insert(g);
    }

    for (int i = 0; i < t; i++){
        int target = arr[i];
        auto k=gold.lower_bound(target);
        if(k==gold.end()){
            cout << -1;
            return 0;
        }
        else{
            ans.push_back(*k);
            gold.erase(k);
        }
    }
    for(auto i:ans){
        cout << i << " ";
    }
}