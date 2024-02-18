#include <bits/stdc++.h>
using namespace std;
vector<int> vis;
bool hasCycle = false;

void dfs(vector<int> adj[], int u)
{
    vis[u] = 1;
    
    if (hasCycle)
        return;

    for (int v : adj[u])
    {
        if (vis[v] == 1)
            hasCycle = true;
        else
            dfs(adj, v);
    }

    vis[u] = 0;
}

void cycleExist(vector<int> adj[], int n)
{
    vis.resize(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            dfs(adj, i);
    }

    if (hasCycle)
        cout << 1;
    else
        cout << 0;
}

int main()
{
    int n;
    cin >> n;

    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;
            if (val == 1)
                adj[i].push_back(j);
        }
    }

    cycleExist(adj, n);

    return 0;
}