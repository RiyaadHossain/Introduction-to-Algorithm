#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> direction = {{-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {2, -1}, {1, 2}, {2, 1}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int attackQueen(vector<vector<int>> &board, int ki, int kj, int qi, int qj, int move)
{
    queue<vector<int>> qu;
    qu.push({ki, kj, 0});
    board[ki][kj] = 1;

    while (!qu.empty())
    {
        vector<int> u = qu.front();
        qu.pop();

        int i = u[0];
        int j = u[1];
        int level = u[2];

        if (i == qi && j == qj)
            return level;

        for (auto dir : direction)
        {
            int mi = i + dir.first;
            int mj = j + dir.second;

            if (isValid(mi, mj) && !board[mi][mj])
            {
                board[mi][mj] = 1;
                qu.push({mi, mj, level + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        vector<vector<int>> board;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j < m; j++)
                temp.push_back(0);

            board.push_back(temp);
        }

        int ki, kj;
        cin >> ki >> kj;

        int qi, qj;
        cin >> qi >> qj;

        int result = attackQueen(board, ki, kj, qi, qj, 0);
        cout << (result < INT_MAX ? result : -1) << endl;
    }

    return 0;
}