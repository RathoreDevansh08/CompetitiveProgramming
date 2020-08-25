// DP for coin change in O(m*n).

#include<bits/stdc++.h>
using namespace std;

int coin_change(int c[], int m, int n)
{
    int dp[n+1][m];

    for(int i=0;i<m;i++) dp[0][i] = 1;

    for(int i=1;i<(n+1);i++)
    {
        for(int j=0;j<m;j++)
        {
            int x = (i >= c[j]) ? dp[ i - c[j] ][j] : 0;
            int y = (j >= 1) ? dp[i][j-1] : 0;

            dp[i][j] = x+y;
        }
    }
    return dp[n][m-1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int coins[] = {1, 2, 3, 5, 10};
    int m = sizeof(coins)/sizeof(coins[0]), n=4;

    cout<< coin_change(coins, m, n) <<"\n";
    return 0;
}
