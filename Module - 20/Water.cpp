#include <bits/stdc++.h>
using namespace std;
using PairInt = pair<int, int>;

PairInt maxWaterContainer(int heights[], int n)
{
    int first = -1, second = -1;

    for (int i = 0; i < n; i++)
    {
        if (first == -1)
            first = i;

        if (first != -1 && heights[first] < heights[i])
            first = i;
    }

    for (int i = 0; i < n; i++)
    {
        if (second == -1 && i != first)
            second = i;

        if (second != -1 && heights[second] < heights[i] && i != first)
            second = i;
    }

    if (first > second)
        return {second, first};

    return {first, second};
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

        PairInt result = maxWaterContainer(arr, n);
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}