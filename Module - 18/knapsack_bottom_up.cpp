#include <bits/stdc++.h>
using namespace std;

int initDP(vector<vector<int>> &dp, int n, int w)
{
    dp.resize(n + 1, vector<int>(w + 1, -1));
    dp[0] = vector<int>(w + 1, 0);

    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;
}

vector<int> value, weight;
int bottomUp(int n, int w)
{
    vector<vector<int>> dp;
    initDP(dp, n, w); // Make every 0th row and column value as 0

    for (int i = 1; i <= n; i++)
    {
        int currWeight = weight[i - 1], currValue = value[i - 1];
        for (int j = 1; j <= w; j++)
        {
            if (currWeight <= j)
            {
                int op1 = dp[i - 1][j - currWeight] + currValue;
                int op2 = dp[i - 1][j];
                dp[i][j] = max(op1, op2);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][w];
}

int main()
{
    int n, w;
    cin >> n >> w;

    value.resize(n), weight.resize(n);

    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];

    int result = bottomUp(n, w);
    cout << result;

    return 0;
}