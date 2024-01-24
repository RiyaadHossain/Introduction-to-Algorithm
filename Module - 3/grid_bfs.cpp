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

void bfs(vector<vector<int>> grid, int si, int sj)
{

    queue<pair<int, int>> qu;
    qu.push({si, sj});
    vis[si][sj] = 1;

    while (!qu.empty())
    {
        pair<int, int> front = qu.front();
        qu.pop();

        int i = front.first;
        int j = front.second;

        cout << grid[i][j] << " ";


        for (auto d : dir)
        {
            int ci = i + d.first;
            int cj = j + d.second;
            if (isValid(ci, cj) && !vis[ci][cj])
            {
                vis[ci][cj] = 1;
                qu.push({ci, cj});
            }
        }
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
    bfs(grid, srcI, srcJ);

    return 0;
}