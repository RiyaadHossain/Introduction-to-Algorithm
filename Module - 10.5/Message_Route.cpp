#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int vis[N];

vector<int> bfs(vector<vector<int>> &computers, int n)
{
    vector<int> trackRoutes(n + 1, -1);
    queue<int> qu;
    qu.push(1);
    vis[1] = 1;

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        for (int v : computers[u])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                qu.push(v);
                trackRoutes[v] = u;
            }
        }
    }

    vector<int> routes;

    if (trackRoutes[n] == -1)
        return routes;

    int i = n;
    while (i != -1)
    {
        routes.push_back(i);
        i = trackRoutes[i];
    }

    cout << endl;

    return routes;
}

vector<int> findRoute(vector<vector<int>> &computers, int n)
{
    vector<int> route = bfs(computers, n);

    reverse(route.begin(), route.end());
    return route;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> computers(n + 1);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        computers[a].push_back(b);
        computers[b].push_back(a);
    }

    vector<int> route = findRoute(computers, n);

    if (!route.empty())
    {
        cout << route.size() << endl;
        for (int it : route)
            cout << it << " ";
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}