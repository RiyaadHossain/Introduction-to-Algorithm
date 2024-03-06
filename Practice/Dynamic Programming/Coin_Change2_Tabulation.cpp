#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> memo;
int coinChange(int arr[], int amount, int idx)
{
    int dp[n + 1][amount + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int currNum = arr[i - 1];
        for (int j = 0; j <= amount; j++)
        {
            if (j >= currNum)
                dp[i][j] = dp[i - 1][j] + dp[i][j - currNum];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][amount];
}

int main()
{
    int amount;
    cin >> n >> amount;
    memo.resize(n + 1, vector<int>(amount + 1, -1));

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = coinChange(arr, amount, 0);
    cout << result;

    return 0;
}