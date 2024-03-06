#include <bits/stdc++.h>
using namespace std;

const int N = 21, M = 101;
int memo[N][N * M];
int value[N], weight[N];

int knapsack(int n, int w)
{
    if (weight == 0 || n == 0)
        return 0;

    if (memo[n][w] != -1)
        return memo[n][w];

    if (weight[n - 1] <= w)
        return memo[n][w] = max(knapsack(n - 1, w - weight[n - 1]) + value[n - 1], knapsack(n - 1, w));

    return memo[n][w] = knapsack(n - 1, w);
}

int main()
{
    int n, w;
    cin >> n >> w;

    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];

    memset(memo, -1, sizeof(memo));

    int result = knapsack(n, w);
    cout << result;

    return 0;
}