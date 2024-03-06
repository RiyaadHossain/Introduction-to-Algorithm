#include <bits/stdc++.h>
using namespace std;

vector<int> g_weight, g_value;
vector<vector<int>> dp;
int recursion(int n, int w)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n][w] != -1)
        return dp[n][w];

    if (w < g_weight[n - 1])
        return dp[n][w] = recursion(n - 1, w);

    int take = recursion(n - 1, w - g_weight[n - 1]) + g_value[n - 1];
    int skip = recursion(n - 1, w);

    return dp[n][w] = max(take, skip);
}

int maxValue(int n, int w, int weight[], int value[])
{
    g_weight.clear(), g_value.clear(), dp.clear();

    g_weight.assign(weight, weight + n);
    g_value.assign(value, value + n);
    dp.resize(n + 1, vector<int>(w + 1, -1));

    return recursion(n, w);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int weight[n];
        for (int i = 0; i < n; i++)
            cin >> weight[i];

        int value[n];
        for (int i = 0; i < n; i++)
            cin >> value[i];

        int result = maxValue(n, w, weight, value);
        cout << result << endl;
    }

    return 0;
}