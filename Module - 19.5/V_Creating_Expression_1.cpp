#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll countTotal(ll arr[], int n)
{
    ll total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    return total;
}

// vector<vector<int>> dp;
unordered_map<string, ll> dp;
bool recursion(ll arr[], int n, ll target)
{
    if (n == 0)
    {
        if (target == 0)
            return 1;
        return 0;
    }

    string key = to_string(n) + '-' + to_string(target);
    if (dp[key])
        return dp[key];

    if (target < arr[n - 1])
        return dp[key] = recursion(arr, n - 1, target);

    bool take = recursion(arr, n - 1, target - arr[n - 1]);
    bool skip = recursion(arr, n - 1, target);

    return dp[key] = take || skip;
}

bool tabulation(ll *arr, int n, int k)
{
    bool dp[k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        ll currNum = arr[i - 1];
        for (int j = 0; j <= k; j++)
        {
            if (j >= currNum)
                dp[j] = dp[j - currNum] || dp[j];
        }
    }

    return dp[k];
}

bool expressionPoss(ll arr[], int n, ll x)
{
    ll total = countTotal(arr, n);
    ll target = (total - x) / 2;

    if (total < x || (total - x) % 2)
        return 0;

    // dp.resize(n + 1, vector<int>(target + 1, -1));
    return recursion(arr, n, target);

    // return tabulation(arr, n, target);
}

int main()
{
    int n, x;
    cin >> n >> x;

    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bool result = expressionPoss(arr, n, x);
    cout << (result ? "YES" : "NO");

    return 0;
}