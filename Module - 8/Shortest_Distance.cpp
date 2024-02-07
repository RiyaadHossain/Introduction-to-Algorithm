#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    ll matrix[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = 1e18;
    }

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;

        if (matrix[u][v] > c)
            matrix[u][v] = c;
    }

    // Floyd Warshall
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int s, d;
        cin >> s >> d;
        cout << (matrix[s][d] < 1e18 ? matrix[s][d] : -1) << endl;
    }

    return 0;
}