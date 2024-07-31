#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pii;

int main()
{
    int t;
    cin >> t;
    int n, m;
    while (t--)
    {
        pii arr[1001] = {};
        cin >> n >> m;
        while (m--)
        {
            int a, b, p, q;
            cin >> a >> b >> p >> q;
            arr[a].first += p;
            arr[a].second += q;
            arr[b].first += q;
            arr[b].second += p;
        }
        double maxR = 0, minR = 1;
        for (int i = 1; i <= n; i++)
        {
            double cur;
            if((pow(arr[i].first, 2) + pow(arr[i].second, 2))==0){
                cur = 0;
                minR = 0;
                continue;
            }
            cur = pow(arr[i].first, 2) / (pow(arr[i].first, 2) + pow(arr[i].second, 2));
            if (maxR < cur)
                maxR = cur;
            if (minR > cur)
                minR = cur;
        }
        cout << floor(maxR * 1000) << '\n';
        cout << floor(minR * 1000) << '\n';
    }
}