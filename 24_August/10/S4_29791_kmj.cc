#include <bits/stdc++.h>

using namespace std;

vector<int> arr1,arr2;

int main()
{
    int n, m,a,b;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a;
        arr1.push_back(a);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b;
        arr2.push_back(b);
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int prei = 0, cnt=0;
    for (auto i : arr1)
    {
        if(prei==0 || (prei + 100)<=i){
            prei = i;
            cnt++;
        }
    }
    cout << cnt << " ";

    prei = 0, cnt = 0;
    for (auto i : arr2)
    {
        if (prei == 0 || (prei + 360) <= i)
        {
            prei = i;
            cnt++;
        }
    }
    cout << cnt;
}