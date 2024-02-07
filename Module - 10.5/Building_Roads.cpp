#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &cities, int src, int vis[])
{
    vis[src] = 1;

    for (int ch : cities[src])
    {
        if (vis[ch] == 0)
            dfs(cities, ch, vis);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> cities(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        cities[a].push_back(b);
        cities[b].push_back(a);
    }

    int vis[n + 1] = {0};

    vector<int> connections = {};

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            connections.push_back(i);
            dfs(cities, i, vis);
        }
    }

    int roadRequired = connections.size() - 1;
    cout << roadRequired << endl;

    for (int i = 0; i < connections.size() - 1; i++)
    {
        int city1 = connections[i];
        int city2 = connections[i + 1];
        cout << city1 << " " << city2 << endl;
    }

    return 0;
}