#include <bits/stdc++.h>
using namespace std;

bool isSubsetSumK(int arr[], int n, int k)
{
    bool dp[n + 1][k + 1];
    memset(dp, false, sizeof(dp));

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int currNum = arr[i - 1];
            if (j >= currNum)
                dp[i][j] = dp[i - 1][j - currNum] || dp[i - 1][j];
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

    int nums[n];
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    bool result = isSubsetSumK(nums, n, k);
    cout << (result ? "YES" : "NO");

    return 0;
}