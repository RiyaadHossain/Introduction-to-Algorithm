#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int dfs(vector<vector<char>> &area, int i, int j)
{
    area[i][j] = '-';

    int areaCell = 1;
    for (auto d : dir)
    {
        int ci = i + d.first;
        int cj = j + d.second;
        if (isValid(ci, cj) && area[ci][cj] == '.')
            areaCell += dfs(area, ci, cj);
    }

    return areaCell;
}

int main()
{
    cin >> n >> m;

    vector<vector<char>> area(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> area[i][j];
    }

    int minArea = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (area[i][j] == '.')
                minArea = min(minArea, dfs(area, i, j));
    }

    cout << (minArea < INT_MAX ? minArea : -1);

    return 0;
}