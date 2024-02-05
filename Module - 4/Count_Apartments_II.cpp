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

int dfs(vector<vector<char>> &grid, int si, int sj)
{
    vis[si][sj] = 1;

    int isCompleteRoom = 1;
    for (auto d : dir)
    {
        int ci = si + d.first;
        int cj = sj + d.second;
        if (isValid(ci, cj) && vis[ci][cj] == 0 && grid[ci][cj] == '.')
            isCompleteRoom += dfs(grid, ci, cj);
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

    vector<int> apratmentRooms;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (vis[i][j] == 0 && grid[i][j] == '.')
                apratmentRooms.push_back(dfs(grid, i, j));
    }

    sort(apratmentRooms.begin(), apratmentRooms.end());

    for (int room : apratmentRooms)
        cout << room << " ";

    if (apratmentRooms.size() == 0)
        cout << 0;

    return 0;
}