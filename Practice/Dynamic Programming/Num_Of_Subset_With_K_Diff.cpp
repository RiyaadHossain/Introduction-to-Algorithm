#include <bits/stdc++.h>
using namespace std;

int knapsack(int arr[], int n, int target)
{
    if (n == 0 && target == 0)
        return 1;
    if (n == 0)
        return 0;

    if (arr[n - 1] <= target)
        return knapsack(arr, n - 1, target - arr[n - 1]) + knapsack(arr, n - 1, target);
    else
        return knapsack(arr, n - 1, target);
}

int tabulation(int arr[], int n, int target)
{
    int dp[n + 1][target + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    sort(arr, arr + n, greater<int>());

    for (int i = 1; i <= n; i++)
    {
        int currNum = arr[i - 1];
        for (int j = 1; j <= target; j++)
        {
            if (j >= currNum)
                dp[i][j] = dp[i - 1][j - currNum] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][target];
}

int countPartitions(int n, int d, int arr[])
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += arr[i];

    if (totalSum <= d || (totalSum - d) % 2)
        return 0;

    int target = (totalSum - d) / 2;

    return tabulation(arr, n, target);
}

int main()
{
    int n, diff;
    cin >> n >> diff;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = countPartitions(n, diff, arr);
    cout << result;

    return 0;
}

// Tabulation
int mod = (int)(1e9 + 7);

int countPartitions2(int n, int d, vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum - d < 0 || (sum - d) % 2 == 1)
        return 0;
    int target = (sum - d) / 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1; // as the iteration starts from the 2nd index

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            int notTake = dp[i - 1][j];
            int Take = 0;
            if (arr[i] <= j)
            {
                Take = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = (Take + notTake) % mod;
        }
    }
    return dp[n - 1][target];
}