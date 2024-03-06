#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr)
{
    for (int it : arr)
        cout << it << " ";

    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int left = 0, right = n - 1;
    int mid = (left + right) / 2;
    vector<int> leftArr(arr + 0, arr + 1);
    vector<int> rightArr(arr + mid + 1, arr + right);

    printArr(leftArr);
    // printArr(rightArr);

    return 0;
}