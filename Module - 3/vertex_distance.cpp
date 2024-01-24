#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int vis[3][4];
int dis[3][4];

bool isValid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
        return true;
    return false;
}

int bfs(vector<vector<int>> grid, int si, int sj, int di, int dj)
{
    int distance = -1;

    queue<pair<int, int>> qu;
    qu.push({si, sj});
    vis[si][sj] = 1;
    dis[si][sj] = 0;

    while (!qu.empty())
    {
        pair<int, int> front = qu.front();
        qu.pop();

        int i = front.first;
        int j = front.second;

        if (i == di && j == dj)
            distance = dis[i][j];

        for (auto d : dir)
        {
            int ci = i + d.first;
            int cj = j + d.second;
            if (isValid(ci, cj) && !vis[ci][cj])
            {
                vis[ci][cj] = 1;
                dis[ci][cj] = dis[i][j] + 1; // track distance (src -> des)
                qu.push({ci, cj});
            }
        }
    }

    return distance;
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
    memset(dis, -1, sizeof(dis));

    int srcI, srcJ, desI, desJ;
    cin >> srcI >> srcJ >> desI >> desJ;

    int result = bfs(grid, srcI, srcJ, desI, desJ);
    cout << "Distance -> " << result;

    return 0;
}