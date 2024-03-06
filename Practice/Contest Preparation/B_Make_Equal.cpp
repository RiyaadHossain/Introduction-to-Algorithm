#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool makeEqual(int arr[], int n)
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    ll avg = sum / n, available = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > avg)
        {
            available += (arr[i] - avg);
        }
        else if (arr[i] < avg)
        {
            ll waterNeeded = avg - arr[i];
            if (waterNeeded > available)
                return false;

            available -= waterNeeded;
        }
    }

    return true;
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

        bool result = makeEqual(arr, n);
        cout << (result ? "YES" : "NO") << '\n';
    }

    return 0;
}