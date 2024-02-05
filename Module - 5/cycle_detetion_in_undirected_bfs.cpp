#include <bits/stdc++.h>
using namespace std;

const int N = 10e5;
vector<int> adj[N];
int vis[N];
int par[N];

bool bfs(int src)
{
    queue<int> qu;
    qu.push(src);
    vis[src] = 1;

    bool cycleDetected = false;

    while (!qu.empty())
    {
        int parent = qu.front();
        qu.pop();

        for (int ch : adj[parent])
        {
            if (par[parent] != ch && vis[ch])
                cycleDetected = true;
            if (vis[ch] == 0)
            {
                vis[ch] = 1;
                par[ch] = parent;
                qu.push(ch);
            }
        }
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
    result = bfs(i);
    }

    cout << (result ? "Cycle Detected" : "Cycle not Detected");

    return 0;
}