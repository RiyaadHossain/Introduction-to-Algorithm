#include <bits/stdc++.h>
using namespace std;

void printShortestDis(vector<int> adj[], int n, int a, int b)
{
    int vis[n + 1];
    int par[n + 1];
    memset(vis, 0, sizeof(vis));
    memset(par, -1, sizeof(par));

    queue<int> qu;
    qu.push(a);
    vis[a] = 1;

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        for (int v : adj[u])
        {
            if (vis[v] == 0)
                qu.push(v), vis[v] = 1, par[v] = u;
        }
    }

    if (par[b] == -1)
    {
        cout << -1;
        return;
    }

    vector<int> path;
    while (b != -1)
        path.push_back(b), b = par[b];

    reverse(path.begin(), path.end());

    cout << path.size() - 1 << endl;
    for (int p : path)
        cout << p << " ";
}

int main()
{
    int n, e;
    cin >> n >> e;

    int a, b;
    cin >> a >> b;

    vector<int> adj[n + 1];
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printShortestDis(adj, n, a, b);

    return 0;
}