#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

const int N = 31;
int vis[N][N];
int n;
vector<pi> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < n) && vis[i][j] == -1;
}

int reachToEnd(vector<char> sunderbans[], pi start, pi end)
{
    memset(vis, -1, sizeof(vis));

    queue<pi> qu;
    qu.push(start);
    vis[start.first][start.second] = 0;

    while (!qu.empty())
    {
        pi src = qu.front();
        qu.pop();

        int i = src.first;
        int j = src.second;

        for (pi d : dir)
        {
            int di = i + d.first;
            int dj = j + d.second;

            if (isValid(di, dj) && sunderbans[di][dj] != 'T')
                qu.push({di, dj}), vis[di][dj] = vis[i][j] + 1;
        }
    }

    return vis[end.first][end.second];
}

int main()
{
    cin >> n;

    vector<char> sunderbans[n + 1];

    pi s, e;
    for (int i = 0; i < n; i++)
    {
        vector<char> temp;
        for (int j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            temp.push_back(ch);

            if (ch == 'S')
                s.first = i, s.second = j;
            if (ch == 'E')
                e.first = i, e.second = j;
        }
        sunderbans[i] = temp;
    }

    cout << reachToEnd(sunderbans, s, e);

    return 0;
}