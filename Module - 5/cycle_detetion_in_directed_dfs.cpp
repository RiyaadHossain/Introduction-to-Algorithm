#include <bits/stdc++.h>
using namespace std;

const int N = 10e5;
vector<int> adj[N];
int vis[N];
int path[N];

bool dfs(int src)
{
    if (vis[src])
        return false;

    vis[src] = 1;
    path[src] = 1;

    bool cycleDetected = false;
    for (int ch : adj[src])
    {
        if (path[ch])
            cycleDetected = true;
        cycleDetected = cycleDetected || dfs(ch);
    }

    path[src] = 0;

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
    }

    memset(vis, 0, sizeof(vis));
    memset(path, 0, sizeof(path));

    bool cycleDetected = false;
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
            cycleDetected = cycleDetected || dfs(i);
    }

    cout << (cycleDetected ? "Cycle Detected" : "Cycle not Detected");
    return 0;
}