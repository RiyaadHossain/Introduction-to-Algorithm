#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{

    // Input
    int v, e;
    cin >> v >> e;

    ll matirx[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i == j)
                matirx[i][j] = 0;
            else
                matirx[i][j] = INT_MAX;
        }
    }

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        matirx[u][v] = c;
    }

    // Floyd Warshall Algo
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (matirx[i][k] + matirx[k][j] < matirx[i][j])
                    matirx[i][j] = matirx[i][k] + matirx[k][j];
            }
        }
    }

    // Output
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cout << matirx[i][j] << " ";
    }

    // Cycle Detection
    bool cycleDetected = false;
    for (int i = 0; i < v; i++)
        if (matirx[i][i] < 0)
            cycleDetected = true;

    return 0;
}