#include <bits/stdc++.h>
using namespace std;
using PairInt = pair<int, int>;

const int N = 1e3 + 1;
int n, m;
int vis[N][N];
PairInt path[N][N];
vector<PairInt> direction = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

bool isValid(vector<vector<char>> &labyrinth, int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m) && !vis[i][j] && labyrinth[i][j] != '#';
}

char findDirection(int i, int j, int di, int dj)
{
    char direction = 'L';

    if (j - 1 == dj)
        direction = 'R';
    if (i + 1 == di)
        direction = 'U';
    if (i - 1 == di)
        direction = 'D';

    return direction;
}

vector<char> bfs(vector<vector<char>> &labyrinth, PairInt src, PairInt des)
{
    // 1. Find path to react destination
    queue<PairInt> qu;
    qu.push(src);
    vis[src.first][src.second] = 1;

    while (!qu.empty())
    {
        PairInt node = qu.front();
        qu.pop();

        int i = node.first;
        int j = node.second;
        for (PairInt dir : direction)
        {
            int ci = i + dir.first;
            int cj = j + dir.second;

            if (isValid(labyrinth, ci, cj))
            {
                vis[ci][cj] = 1;
                qu.push({ci, cj});
                path[ci][cj] = {i, j};
            }
        }
    }

    // 2. Extract directions
    int i = des.first;
    int j = des.second;

    vector<char> extractedPath;
    while (i != src.first || j != src.second)
    {
        int di = path[i][j].first;
        int dj = path[i][j].second;

        extractedPath.push_back(findDirection(i, j, di, dj));
        i = di, j = dj;
    }

    reverse(extractedPath.begin(), extractedPath.end());

    return extractedPath;
}

vector<char> solveLabyrinth(vector<vector<char>> &labyrinth, PairInt src, PairInt des)
{
    n = labyrinth.size();
    m = labyrinth[0].size();
    memset(vis, 0, sizeof(vis));
    memset(path, -1, sizeof(path));

    return bfs(labyrinth, src, des);
}

int main()
{
    int n, m;
    cin >> n >> m;

    PairInt src, des;
    vector<vector<char>> labyrinth(n);
    for (int i = 0; i < n; i++)
    {
        vector<char> temp(m);
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            temp[j] = ch;

            if (ch == 'A')
                src.first = i, src.second = j;
            if (ch == 'B')
                des.first = i, des.second = j;
        }
        labyrinth[i] = temp;
    }

    vector<char> path = solveLabyrinth(labyrinth, src, des);

    int pathCount = path.size();
    cout << (pathCount ? "YES" : "NO") << endl
         << pathCount << endl;

    for (char p : path)
        cout << p;

    return 0;
}