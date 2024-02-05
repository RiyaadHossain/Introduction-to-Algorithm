#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int vis[N][N];

int n, m;

vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(vector<vector<char>> &mat, bool &isSame, int si, int sj, int di, int dj)
{
    vis[si][sj] = 1;

    if (si == di && sj == dj)
        isSame = true;

    for (auto d : dir)
    {
        int ci = si + d.first;
        int cj = sj + d.second;
        if (isValid(ci, cj) && !vis[ci][cj] && mat[ci][cj] != '-')
            dfs(mat, isSame, ci, cj, di, dj);
    }
}

bool sameComponet(vector<vector<char>> &mat, int si, int sj, int di, int dj)
{
    n = mat.size();
    m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            vis[i][j] = 0;
    }

    bool isSame = false;
    dfs(mat, isSame, si, sj, di, dj);

    return isSame;
}

int main()
{
    // Input
    int n, m;
    cin >> n >> m;

    vector<vector<char>> mat(n);
    for (int i = 0; i < n; i++)
    {
        vector<char> temp;
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            temp.push_back(ch);
        }

        mat[i] = temp;
    }

    int si, sj;
    cin >> si >> sj;

    int di, dj;
    cin >> di >> dj;

    // Calculate
    bool isSameComponent = sameComponet(mat, si, sj, di, dj);

    // Output
    cout << (isSameComponent ? "YES" : "NO");

    return 0;
}