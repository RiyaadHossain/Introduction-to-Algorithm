#include <bits/stdc++.h>
using namespace std;

const int N = 10e5;
vector<int> adj[N];
int vis[N];
int par[N];

bool dfs(int src)
{
    if (vis[src])
        return false;

    vis[src] = 1;
    bool cycleDetected = false;
    for (int ch : adj[src])
    {
        if (par[src] != ch && vis[ch])
            cycleDetected = true;
        if (vis[ch] == 0)
            par[ch] = src;

        cycleDetected = cycleDetected || dfs(ch);
    }

    return cycleDetected;
}

int main()
{
    int v, e;
    cin >> v >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(vis, 0, sizeof(vis));
    memset(par, -1, sizeof(par));

    bool result = false;
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
            result = result || dfs(i);
    }

    cout << (result ? "Cycle Detected" : "Cycle not Detected");
    return 0;
}