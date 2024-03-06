#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int vis[3][4];

bool isValid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
        return true;
    return false;
}

void dfs(vector<vector<int>> grid, int si, int sj)
{
    vis[si][sj] = 1;

    for (auto d : dir)
    {
        int ci = si + d.first;
        int cj = sj + d.second;
        if (isValid(ci, cj) && !vis[ci][cj])
            dfs(grid, ci, cj);
    }
}

int main()
{
    cin >> n >> m;

    vector<vector<int>> grid;

    for (int i = 0; i < n; i++)
    {
        vector<int> col;
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            col.push_back(val);
        }
        grid.push_back(col);
    }

    memset(vis, 0, sizeof(vis));

    int srcI, srcJ;
    cin >> srcI >> srcJ;
    dfs(grid, srcI, srcJ);

    return 0;
}