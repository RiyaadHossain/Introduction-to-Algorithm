#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

const int N = 1e2;
int vis[N][N];

int col, row;
vector<pi> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < row && j >= 0 && j < col) && (vis[i][j] == -1);
}

int dfsHelper(vector<char> island[], int i, int j)
{
    vis[i][j] = 1;

    int cellCanBeReached = 1;
    for (pi d : dir)
    {
        int ci = i + d.first;
        int cj = j + d.second;

        if (isValid(ci, cj) && island[ci][cj] != '#')
            cellCanBeReached += dfsHelper(island, ci, cj);
    }

    return cellCanBeReached;
}

int numberOfCell(vector<char> island[], pi start)
{
    memset(vis, -1, sizeof(vis));

    return dfsHelper(island, start.first, start.second);
}

int main()
{
    int t, i = 0;
    cin >> t;

    while (i < t)
    {
        cin >> col >> row;

        vector<char> island[row];

        pi start;
        for (int i = 0; i < row; i++)
        {
            vector<char> temp;
            for (int j = 0; j < col; j++)
            {
                char ch;
                cin >> ch;
                temp.push_back(ch);

                if (ch == '@')
                    start.first = i, start.second = j;
            }
            island[i] = temp;
        }

        string _case = "Case " + to_string(i + 1) + ": ";
        cout << _case << numberOfCell(island, start) << endl;

        i++;
    }

    return 0;
}