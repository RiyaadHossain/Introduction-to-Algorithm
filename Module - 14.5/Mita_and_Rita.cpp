#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

const int N = 31;
int vis[N][N];
int n;
vector<pi> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < n) && (vis[i][j] == -1);
}

int reachToDes(vector<char> house[], pi src, pi des)
{
    memset(vis, -1, sizeof(vis));

    queue<pi> qu;
    qu.push(src);
    vis[src.first][src.second] = 0;

    while (!qu.empty())
    {
        pi front = qu.front();
        qu.pop();

        int i = front.first;
        int j = front.second;

        for (pi d : dir)
        {
            int ci = i + d.first;
            int cj = j + d.second;

            if (isValid(ci, cj) && house[ci][cj] != 'O')
                qu.push({ci, cj}), vis[ci][cj] = vis[i][j] + 1;
        }
    }

    return vis[des.first][des.second];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;

        vector<char> house[n];
        pi mita, rita, des;
        for (int i = 0; i < n; i++)
        {
            vector<char> temp;
            for (int j = 0; j < n; j++)
            {
                char ch;
                cin >> ch;
                temp.push_back(ch);

                if (ch == 'M')
                    mita = {i, j};
                if (ch == 'R')
                    rita = {i, j};
                if (ch == 'D')
                    des = {i, j};
            }
            house[i] = temp;
        }

        int result = reachToDes(house, mita, rita) + reachToDes(house, rita, des);
        cout << (result < 0 ? -1 : result) << endl;
    }

    return 0;
}