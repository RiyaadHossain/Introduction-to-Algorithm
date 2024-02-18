#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

const int N = 301;
int n;
int vis[N][N];
vector<pi> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < n) && (vis[i][j] == 0);
}

void isPossibleToMove(vector<char> table[], int n, pi start, pi end)
{
    pi path[n][n];

    memset(vis, 0, sizeof(vis));
    memset(path, -1, sizeof(path));

    queue<pi> qu;
    qu.push(start);
    vis[start.first][start.second] = 1;

    while (!qu.empty())
    {
        pi u = qu.front();
        qu.pop();

        int ui = u.first, uj = u.second;
        for (pi d : dir)
        {
            int i = ui + d.first, j = uj + d.second;
            if (isValid(i, j) && table[i][j] != 'O')
                qu.push({i, j}), vis[i][j] = 1, path[i][j] = {ui, uj};
        }
    }

    int ei = end.first, ej = end.second;
    if (path[ei][ej].first == -1)
    {
        cout << 'N';
        return;
    }

    int si = start.first, sj = start.second;
    while (ei != si || ej != sj)
    {
        int ti = ei, tj = ej;

        table[ei][ej] = '+';
        ei = path[ti][tj].first;
        ej = path[ti][tj].second;
    }

    cout << 'Y' << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << table[i][j];
        cout << endl;
    }
}

int main()
{
    cin >> n;

    vector<char> table[n];

    pi start, end;
    for (int i = 0; i < n; i++)
    {
        vector<char> temp;
        for (int j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            temp.push_back(ch);

            if (ch == '@')
                start = {i, j};
            if (ch == 'X')
                end = {i, j};
        }

        table[i] = temp;
    }

    isPossibleToMove(table, n, start, end);

    return 0;
}