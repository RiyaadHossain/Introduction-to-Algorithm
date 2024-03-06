#include <bits/stdc++.h>
using namespace std;

int tabulation(vector<int> &arr, int n, int k)
{
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int currNum = arr[i - 1];
        for (int j = 0; j <= k; j++)
        {
            if (j >= currNum)
                dp[i][j] = dp[i - 1][j - currNum] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
        cout << endl;
    }

    return dp[n][k];
}

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = tabulation(arr, n, k);
    cout << result;

    return 0;
}