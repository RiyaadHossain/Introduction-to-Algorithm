#include <bits/stdc++.h>
using namespace std;

vector<int> memo;
int coinChange(int arr[], int n, int amount)
{
    if (amount == 0)
        return 0;

    if (memo[amount] != -1)
        return memo[amount];

    int coinTaken = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (amount >= arr[i])
            coinTaken = min(coinTaken, coinChange(arr, n, amount - arr[i]));
    }

    memo[amount] = coinTaken != INT_MAX ? coinTaken + 1 : INT_MAX;
    return memo[amount];
}

int main()
{
    int n, amount;
    cin >> n >> amount;
    memo.resize(amount + 1, -1);

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = coinChange(arr, n, amount);
    cout << (result != INT_MAX ? result : -1);

    return 0;
}