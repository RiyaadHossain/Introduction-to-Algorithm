#include <bits/stdc++.h>
using namespace std;

int countOfSubsetEqualK(int arr[], int n, int k)
{
    int dp[n + 1][k + 1];

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int currNum = arr[i - 1];
        for (int j = 1; j <= k; j++)
        {
            if (j >= currNum)
                dp[i][j] = dp[i - 1][j - currNum] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = countOfSubsetEqualK(arr, n, k);
    cout << result;

    return 0;
}