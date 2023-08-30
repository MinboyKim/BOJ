#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
pii bag[101];
int dp[101][101001];

int main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int n, v;
        cin >> bag[i].first >> bag[i].second;
    }

    for (int i = bag[0].first; i <= k; i++)
    {
        dp[0][i] = bag[0].second;
    }

    for (int i = 1; i < n; i++)
    { // 넣을수 있는 무게와 가치
        for (int j = 1; j <= k; j++)
        { // 배낭 무게가 1씩증가
            if (j - bag[i].first < 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], bag[i].second + dp[i - 1][j - bag[i].first]);
            }
        }
    }

    cout << dp[n - 1][k];
}