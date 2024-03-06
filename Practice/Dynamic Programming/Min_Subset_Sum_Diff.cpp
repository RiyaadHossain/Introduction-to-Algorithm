#include <bits/stdc++.h>
using namespace std;

int totalSum = 0;
int minDiff = INT_MAX;
void solve(int arr[], int n, int sum)
{
    if (n == 0)
        return;

    int currDiff = abs(totalSum - sum * 2);
    if (minDiff > currDiff)
        minDiff = currDiff;

    solve(arr, n - 1, sum + arr[n - 1]);
    solve(arr, n - 1, sum);
}

int tabulaiton(int arr[], int n)
{
    int dp[n + 1][totalSum + 1];
    memset(dp, false, sizeof(dp));

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        int currNum = arr[i - 1];
        for (int j = 0; j <= totalSum; j++)
        {
            if (j >= currNum)
                dp[i][j] = dp[i - 1][j - currNum] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int minDiff = INT_MAX;
    for (int i = totalSum / 2; i >= 0; i--)
        if (dp[n][i] && minDiff > abs(totalSum - i * 2))
            minDiff = abs(totalSum - i * 2);

    return minDiff;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i], totalSum += arr[i];

    // solve(arr, n, 0);
    cout << tabulaiton(arr, n);

    return 0;
}