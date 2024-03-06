#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
map<string, int> dp;

string makeKey(int l, int r, int cnt)
{
    return to_string(l) + '-' + to_string(r) + '-' + to_string(cnt);
}

int recursion(int left, int right, int x, int cnt)
{
    if (x == 0)
        return cnt;

    if (left == right || x < 0)
        return INT_MAX;

    string key = makeKey(left, right, cnt);
    if (dp[key] != 0)
        return dp[key];

    int l = recursion(left + 1, right, x - nums[left], cnt + 1);
    int r = recursion(left, right - 1, x - nums[right], cnt + 1);

    return dp[key] = min(l, r);
}

int minOperationToX(int arr[], int n, int x)
{
    nums.assign(arr, arr + n);
    int result = recursion(0, n - 1, x, 0);
    return result != INT_MAX ? result : -1;
}

int main()
{
    int n, x;
    cin >> n >> x;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = minOperationToX(arr, n, x);
    cout << result;

    return 0;
}