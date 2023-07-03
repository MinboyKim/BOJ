#include <bits/stdc++.h>

using namespace std;

int t, n;
int deck[1010];
int score[1010];
int myscore;
int dp[1010][1010];
int solve(int left, int right,int turn);

int solve(int left, int right,int turn){
    if(left>right) return 0;

    if (dp[left][right]) return dp[left][right];

    if(turn==1){
        return dp[left][right]=max(deck[left]+solve(left+1, right,0), deck[right]+solve(left, right-1,0));
    }
    if(turn==0){
        return dp[left][right]=min(solve(left, right - 1,1), solve(left + 1, right,1));
    }
}

int main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> deck[i];
        
        cout<<solve(1, n, 1)<<'\n';
        fill(&dp[0][0], &dp[1010][1010], 0); 
    }

    return 0;

    
}