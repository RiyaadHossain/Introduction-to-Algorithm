#include <bits/stdc++.h>
using namespace std;

vector<int> boxes;
vector<vector<int>> dp;
bool targetSum(int n, int target)
{
    if (n == 0)
    {
        if (target == 0)
            return 1;
        return 0;
    }

    if (dp[n][target] != -1)
        return dp[n][target];

    if (target < boxes[n - 1])
        return dp[n][target] = targetSum(n - 1, target);

    int take = targetSum(n - 1, target - boxes[n - 1]);
    int skip = targetSum(n - 1, target);

    return dp[n][target] = take || skip;
}

int tabulation(int n, int target)
{
    bool memo[n + 1][target + 1];
    memset(memo, 0, sizeof(memo));
    memo[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int currNum = boxes[i - 1];
        for (int j = 0; j <= target; j++)
        {
            if (j >= currNum)
                memo[i][j] = memo[i - 1][j - currNum] || memo[i - 1][j];
            else
                memo[i][j] = memo[i - 1][j];
        }
    }

    return memo[n][target];
}

int getTotal(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    return total;
}

bool isDivisible(int arr[], int n)
{
    boxes.clear();
    boxes.assign(arr, arr + n);

    int total = getTotal(arr, n);
    int target = total / 2;

    if (total % 2)
        return 0;

    // dp.clear();
    // dp.resize(n + 1, vector<int>(target + 1, -1));

    return tabulation(n, target);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        bool result = isDivisible(arr, n);
        cout << (result ? "YES" : "NO") << endl;
    }

    return 0;
}