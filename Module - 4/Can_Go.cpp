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

bool dfs(vector<vector<char>> &grid, int si, int sj)
{
    vis[si][sj] = 1;

    bool canGo = grid[si][sj] == 'B' ? true : false;
    for (auto d : dir)
    {
        int ci = si + d.first;
        int cj = sj + d.second;
        if (isValid(ci, cj) && vis[ci][cj] == 0 && grid[ci][cj] != '#')
            canGo = canGo || dfs(grid, ci, cj);
    }

    return canGo;
}

int main()
{
    cin >> n >> m;
    vector<vector<char>> grid;

    int srcI, srcJ;
    for (int i = 0; i < n; i++)
    {
        vector<char> temp;
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            temp.push_back(ch);

            if (ch == 'A')
                srcI = i, srcJ = j;
        }
        grid.push_back(temp);
    }

    memset(vis, 0, sizeof(vis));

    bool canGo = dfs(grid, srcI, srcJ);

    cout << (canGo ? "YES" : "NO") << endl;

    return 0;
}