#include <bits/stdc++.h>
#define ll long long
using namespace std;
using PairV = pair<int, int>;

int main()
{
    // Input
    int n;
    cin >> n;

    int mat[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int e;
            cin >> e;
            mat[i][j] = e;
        }
    }

    // Calculation
    ll dis[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dis[i][j] = INT_MAX;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][k] + mat[k][j] < mat[i][j])
                    mat[i][j] = mat[i][k] + mat[k][j];
            }
        }
    }

    // Output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}