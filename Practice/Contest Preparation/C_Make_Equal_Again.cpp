#include <bits/stdc++.h>
using namespace std;

int minCost(int arr[], int n)
{
    int firstVal = arr[0], lastVal = arr[n - 1];

    int firstValFreq = 0, lastValFreq = 0;

    int i = 0;
    while (i < n && arr[i] == firstVal)
        firstValFreq++, i++;

    i = n - 1;
    while (i >= 0 && arr[i] == lastVal)
        lastValFreq++, i--;

    if (firstValFreq == n)
        return 0;

    if (firstVal == lastVal)
        return n - (firstValFreq + lastValFreq);

    return n - (max(firstValFreq, lastValFreq));
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

        int result = minCost(arr, n);
        cout << result << '\n';
    }

    return 0;
}