#include <bits/stdc++.h>
using namespace std;

void fillDP(int dp[], int n)
{
    for (int i = 0; i < n; i++)
        dp[i] = INT_MAX;
}

int coinChange(int arr[], int n, int amount)
{
    int dp[amount + 1];
    fillDP(dp, amount + 1);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int currNum = arr[i];
        for (int j = 1; j <= amount; j++)
        {
            if (currNum <= j && dp[j - currNum] != INT_MAX)
                dp[j] = min(dp[j], dp[j - currNum] + 1);
        }
    }

    return dp[amount] != INT_MAX ? dp[amount] : -1;
}

int main()
{
    int n, amount;
    cin >> n >> amount;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = coinChange(arr, n, amount);
    cout << result;

    return 0;
}