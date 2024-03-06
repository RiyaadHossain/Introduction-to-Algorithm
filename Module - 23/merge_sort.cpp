#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    vector<int> leftArr(arr + left, arr + mid + 1);
    vector<int> rightArr(arr + mid + 1, arr + right + 1);

    int i = 0, j = 0, curr = left;
    while (i < leftArr.size() && j < rightArr.size())
    {
        if (leftArr[i] <= rightArr[j])
            arr[curr] = leftArr[i], i++;
        else
            arr[curr] = rightArr[j], j++;

        curr++;
    }

    while (i < leftArr.size())
    {
        arr[curr] = leftArr[i];
        i++, curr++;
    }
    while (j < rightArr.size())
    {
        arr[curr] = rightArr[j];
        j++, curr++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left == right)
        return;

    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}