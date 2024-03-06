#include <bits/stdc++.h>
using namespace std;

int recursion(int arr[], int idx, int target)
{
    if (idx < 0)
        return target;

    if (arr[idx - 1] > target)
        return recursion(arr, idx - 1, target);

    int take = recursion(arr, idx - 1, target - arr[idx - 1]);
    int skip = recursion(arr, idx - 1, target);

    return min(take, skip);
}

int tabulation(int arr[], int n, int target)
{
    bool dp[n + 1][target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int currNum = arr[i - 1];
        for (int j = 0; j <= target; j++)
        {
            if (j >= currNum)
                dp[i][j] = dp[i - 1][j - currNum] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int maxSum = target;
    while (dp[n][maxSum] != 1)
        maxSum--;

    return target - maxSum;
}

int minSubsetSumDiff(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] < 0 ? abs(arr[i]) * 3 : arr[i]);

    int total = 0;
    for (int i = 0; i < n; i++)
        total += abs(arr[i]);

    int target = total / 2;
    int subSetSum = recursion(arr, n, target);
    // int subSetSum = tabulation(arr, n, target);

    return (subSetSum * 2) + (total % 2);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = minSubsetSumDiff(arr, n);
    cout << result;

    return 0;
}