#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

const int N = 1e3;
int vis[N][N];
pi par[N][N];

int n, m;
vector<pi> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m) && vis[i][j] == 0;
}

void printMaze(vector<vector<char>> &maze)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << maze[i][j];
        cout << endl;
    }
}

void solveMaze(vector<vector<char>> &maze, pi rezia, pi des)
{
    queue<pi> qu;
    qu.push(rezia);
    vis[rezia.first][rezia.second] = 1;

    while (!qu.empty())
    {
        pi rezia = qu.front();
        qu.pop();

        int i = rezia.first, j = rezia.second;
        for (pi d : dir)
        {
            int di = d.first, dj = d.second;
            int mi = i + di, mj = j + dj;
            if (isValid(mi, mj) && maze[mi][mj] != '#')
                qu.push({mi, mj}), vis[mi][mj] = 1, par[mi][mj] = {i, j};
        }
    }

    if (par[des.first][des.second].first == -1)
        return;

    // Mark on the maze
    des = par[des.first][des.second];
    while (des != rezia)
        maze[des.first][des.second] = 'X', des = par[des.first][des.second];
}

int main()
{
    cin >> n >> m;

    pi rezia, des;
    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];

            if (maze[i][j] == 'R')
                rezia = {i, j};
            if (maze[i][j] == 'D')
                des = {i, j};
        }
    }

    memset(vis, 0, sizeof(vis));
    memset(par, -1, sizeof(par));

    solveMaze(maze, rezia, des);
    printMaze(maze);

    return 0;
}