#include <bits/stdc++.h>

using namespace std;

int n;
double avg;
int arr[300003];

int main()
{
    // cin >> n;
    // if(!n){
    //     cout<<0;
    //     return 0;
    // }

    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];

    // sort(arr, arr + n);
    // double del = n * 0.15;
    // del = round(del);

    // for (int i = del; i < n - del; i++)
    // {
    //     avg += arr[i];
    // }

    // avg = avg / (n-del*2);

    // cout << round(avg);
    int arr[3][3];

    cout<<&arr[0][0]<<'\n';
    cout<<&arr[0][1]<<'\n';
    cout<<&arr[0][2]<<'\n';
    cout<<arr[1]<<'\n';
    cout<<&arr[1][1]<<'\n';
    cout<<&arr[1][2]<<'\n';
    cout<<arr[2]<<'\n';
    cout<<arr[2]+1;



    return 0;
}