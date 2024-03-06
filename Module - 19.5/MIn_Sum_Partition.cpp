#include <bits/stdc++.h>
using namespace std;

int getTotal(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    return total;
}

void makeAbsArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = arr[i] >= 0 ? arr[i] : abs(arr[i]) * 3;
}

int recursion(int arr[], int n, int target)
{
    if (n == 0)
        return target;

    if (target < arr[n - 1])
        return recursion(arr, n - 1, target);

    int take = recursion(arr, n - 1, target - arr[n - 1]);
    int skip = recursion(arr, n - 1, target);

    return min(take, skip);
}

int minSumPartition(int arr[], int n)
{
    makeAbsArr(arr, n);
    int total = getTotal(arr, n);
    int target = total / 2;

    int minSum = recursion(arr, n, target);
    cout << target << " " << minSum << endl;
    return minSum * 2 + (total % 2);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = minSumPartition(arr, n);
    cout << result;

    return 0;
}