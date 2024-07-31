#include <bits/stdc++.h>

using namespace std;

int arr[101];
queue<int> st;

int main()
{
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        for (int r = b; r >= a; r--){
            st.push(arr[r]);     
        }

        for (int r = a; r <= b; r++){
            arr[r] = st.front();
            st.pop();
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}