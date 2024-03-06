#include <bits/stdc++.h>
using namespace std;

const int N = 1e2;
int memo[N][N];

bool kanpsack(vector<int> &nums, int targetSum, int n)
{
    if (targetSum == 0)
        return true;

    if (n <= 0)
        return false;

    int currNum = nums[n - 1];

    if (memo[currNum][targetSum] != -1)
        return memo[currNum][targetSum];

    if (currNum <= targetSum)
        return memo[currNum][targetSum] = (kanpsack(nums, targetSum - currNum, n - 1) || kanpsack(nums, targetSum, n - 1));
    else
        return memo[currNum][targetSum] = kanpsack(nums, targetSum, n - 1);
}

bool tabulation(vector<int> &nums, int targetSum, int n)
{
    bool memo[n + 1][targetSum + 1];
    memset(memo, false, sizeof(memo));
    for (int i = 0; i <= n; i++)
        memo[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        int currNum = nums[i - 1];
        for (int j = 1; j <= targetSum; j++)
        {
            if (currNum <= j)
                memo[i][j] = (memo[i - 1][j - currNum] || memo[i - 1][j]);
            else
                memo[i][j] = memo[i - 1][j];
        }
    }

    return memo[n][targetSum];
}

bool subSetSum(vector<int> &nums, int targetSum)
{
    int n = nums.size();
    memset(memo, -1, sizeof(memo));

    return tabulation(nums, targetSum, n);
}

int main()
{
    int targetSum;
    cin >> targetSum;

    int val;
    vector<int> nums;
    while (cin >> val)
        nums.push_back(val);

    bool isSubsetSum = subSetSum(nums, targetSum);
    cout << (isSubsetSum ? "YES" : "NO");

    return 0;
}