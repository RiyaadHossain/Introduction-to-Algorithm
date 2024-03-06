#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 11;
int memo[N][N];

int n, m;
int maxPath(vector<vector<int>> &matrix, int i, int j)
{
    if (i == n || j == m)
        return 0;

    // if (memo[i][j] != -1)
    //     return memo[i][j];

    int path1 = 0, path2 = 0;
    if (i < n)
        path1 = maxPath(matrix, i + 1, j);
    if (j < m)
        path2 = maxPath(matrix, i, j + 1);

    return /* memo[i][j] = */ max(path1, path2) + matrix[i][j];
}

int main()
{
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }

    memset(memo, -1, sizeof(memo));

    int result = maxPath(matrix, 0, 0);

    cout << result;

    return 0;
}