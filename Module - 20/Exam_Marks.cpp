#include <bits/stdc++.h>
using namespace std;

vector<int> marks;
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

    if (target < marks[n - 1])
        return dp[n][target] = targetSum(n - 1, target);

    int take = targetSum(n - 1, target - marks[n - 1]);
    int skip = targetSum(n - 1, target);

    return dp[n][target] = take || skip;
}

int getTotal(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    return total;
}

bool canHeObtain(int arr[], int n, int m)
{
    marks.clear();
    marks.assign(arr, arr + n);

    int total = getTotal(arr, n);
    int markNeed = 1000 - m;

    if (total < markNeed)
        return 0;

    dp.clear();
    dp.resize(n + 1, vector<int>(markNeed + 1, -1));

    return targetSum(n, markNeed);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        bool result = canHeObtain(arr, n, m);
        cout << (result ? "YES" : "NO") << endl;
    }

    return 0;
}