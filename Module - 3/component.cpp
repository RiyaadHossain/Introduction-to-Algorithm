#include <bits/stdc++.h>
using namespace std;

const int n = 1e2;

int vis[n];

void dfs(vector<int> graph[], int src)
{
    vis[src] = 1;

    for (int ch : graph[src])
        if (!vis[ch])
            dfs(graph, ch);
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> graph[v];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // For Undirected graph
    }

    memset(vis, 0, sizeof(vis));

    int components = 0;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(graph, i), components++;
    }

    cout << "Components -> " << components;

    return 0;
}