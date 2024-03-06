#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int solve(int rod[], int idx, int len)
{
    if (idx <= 0 || len <= 0)
        return 0;

    if (dp[idx][len] != -1)
        return dp[idx][len];

    if (idx > len)
        return dp[idx][len] = solve(rod, idx - 1, len);

    int take = solve(rod, idx, len - idx) + rod[idx - 1];
    int skip = solve(rod, idx - 1, len);

    return dp[idx][len] = max(take, skip);
}

int tabulation(int rod[], int n)
{
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        int currNum = rod[i - 1];
        for (int j = 0; j <= n; j++)
        {
            if (j >= i)
                dp[i][j] = max(dp[i][j - i] + currNum, dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][n];
}

int maxProfit(int rod[], int n)
{
    // dp.resize(n + 1, vector<int>(n + 1, -1)); // initialize dp array
    // return solve(rod, n, n);

    return tabulation(rod, n);
}

int main()
{
    int n;
    cin >> n;

    int rod[n];
    for (int i = 0; i < n; i++)
        cin >> rod[i];

    int result = maxProfit(rod, n);
    cout << result;

    return 0;
}