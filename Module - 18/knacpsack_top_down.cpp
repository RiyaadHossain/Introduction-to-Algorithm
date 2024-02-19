#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
void initDP(int n, int w)
{
    dp.resize(n, vector<int>(w, -1));
}

vector<int> value, weight;
int knapsack(int n, int w)
{
    if (n <= 0 || w == 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

    if (weight[n - 1] <= w)
    {
        int val1 = knapsack(n - 1, w - weight[n - 1]) + value[n - 1];
        int val2 = knapsack(n - 1, w);
        return dp[n][w] = max(val1, val2);
    }
    else
        return dp[n][w] = knapsack(n - 1, w);
}

int main()
{
    int n, w;
    cin >> n >> w;

    // Initialize DP
    initDP(n + 1, w + 1);

    value.resize(n), weight.resize(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];

    int result = knapsack(n, w);
    cout << result;

    return 0;
}