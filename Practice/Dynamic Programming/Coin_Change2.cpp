#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;
int n;
int coinChange(int arr[], int amount, int idx)
{
    if (amount == 0)
        return 1;

    if (memo[idx][amount] != -1)
        return memo[idx][amount];

    int makeChange = 0;
    for (int i = idx; i < n; i++)
        if (amount >= arr[i])
            makeChange += coinChange(arr, amount - arr[i], i);

    return memo[idx][amount] = makeChange;
}

int coinChange2(int arr[], int amount, int idx)
{
    if (amount == 0)
        return 1;

    if (idx == n)
        return 0;

    if (amount < arr[idx])
        return coinChange2(arr, amount, idx + 1);

    int take = coinChange2(arr, amount - arr[idx], idx);
    int skip = coinChange2(arr, amount, idx + 1);

    return take + skip;
}

int main()
{
    int amount;
    cin >> n >> amount;
    memo.resize(n + 1, vector<int>(amount + 1, -1));

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = coinChange(arr, amount, 0);
    cout << result;

    return 0;
}