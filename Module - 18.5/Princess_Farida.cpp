#include <bits/stdc++.h>
using namespace std;

vector<int> memo;
int collectGolds(int arr[], int n)
{
    if (n <= 0)
        return 0;

    if (memo[n - 1] != -1)
        return memo[n-1];

    return memo[n-1] = max(collectGolds(arr, n - 1), collectGolds(arr, n - 2) + arr[n - 1]);
}

int main()
{
    int t;
    cin >> t;

    int idx = 1;
    while (idx <= t)
    {
        int n;
        cin >> n;

        memo.resize(n, -1);

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << "Case " << idx << ": " << collectGolds(arr, n) << endl;
        memo.clear();
        idx++;
    }

    return 0;
}