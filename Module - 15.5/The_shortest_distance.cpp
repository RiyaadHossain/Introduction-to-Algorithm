#include <bits/stdc++.h>
using namespace std;

void printShortestDis(vector<int> adj[], int n, int x)
{
    int dis[n + 1];
    memset(dis, -1, sizeof(dis));

    queue<int> qu;
    qu.push(x);
    dis[x] = 0;

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        for (int v : adj[u])
        {
            if (dis[v] == -1)
                qu.push(v), dis[v] = dis[u] + 1;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int val;
            cin >> val;
            if (val == 1)
                adj[i].push_back(j);
        }
    }

    printShortestDis(adj, n, x);

    return 0;
}