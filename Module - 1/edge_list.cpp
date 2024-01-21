#include <bits/stdc++.h>
using namespace std;

int main()
{

    /*
        Data Structure: pair of array
        Best at: working with edges
     */

    int n, e;
    cin >> n, e;

    pair<int, int> mat[n];
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        mat[i] = {a, b};
    }

    return 0;
}