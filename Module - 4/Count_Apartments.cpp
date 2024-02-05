#include <bits/stdc++.h>
using namespace std;

const int v = 10e3;

int n, m;
int vis[v][v];
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

bool completeRoom(vector<vector<char>> &grid, int si, int sj)
{
    bool isRoom = true;

    for (auto d : dir)
    {
        int ci = si + d.first;
        int cj = sj + d.second;
        if (isValid(ci, cj) && vis[ci][cj] == 0 && grid[ci][cj] == '.')
            isRoom = false;
    }

    return isRoom;
}

int dfs(vector<vector<char>> &grid, int si, int sj)
{
    vis[si][sj] = 1;

    int isCompleteRoom = completeRoom(grid, si, sj) ? 1 : 0;
    for (auto d : dir)
    {
        int ci = si + d.first;
        int cj = sj + d.second;
        if (isValid(ci, cj) && vis[ci][cj] == 0 && grid[ci][cj] != '#')
            isCompleteRoom = max(isCompleteRoom, dfs(grid, ci, cj));
    }

    return isCompleteRoom;
}

int main()
{
    cin >> n >> m;
    vector<vector<char>> grid;

    for (int i = 0; i < n; i++)
    {
        vector<char> temp;
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            temp.push_back(ch);
        }
        grid.push_back(temp);
    }

    memset(vis, 0, sizeof(vis));

    int apratments = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (vis[i][j] == 0 && grid[i][j] == '.')
                apratments += dfs(grid, i, j);
    }

    cout << apratments << endl;

    return 0;
}