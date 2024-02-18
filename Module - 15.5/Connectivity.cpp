#include <bits/stdc++.h>
using namespace std;

vector<int> vis;

void dfs(vector<int> adj[], int u)
{
    vis[u] = 1;

    for (int v : adj[u])
        if (vis[v] == 0)
            dfs(adj, v);
}

int main()
{
    int n, e;
    cin >> n >> e;
    vis.resize(n + 1, 0);

    vector<int> adj[n + 1];
    while (e--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int component = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(adj, i), component++;
    }

    if (component > 1)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}