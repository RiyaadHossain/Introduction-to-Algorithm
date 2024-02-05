#include <bits/stdc++.h>
using namespace std;

/*
    Question: You will be given an undirected graph as input. You need to tell the number of components in this graph.
*/

const int n = 10e2;
int vis[n];

void dfs(vector<vector<int>> &graph, int src)
{
    vis[src] = 1;

    for (int ch : graph[src])
    {
        if (vis[ch] == 0)
            dfs(graph, ch);
    }
}

int components(vector<vector<int>> &graph)
{
    memset(vis, 0, sizeof(vis));

    int comps = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        if (vis[i] == 0)
        {
            comps++;
            dfs(graph, i);
        }
    }

    return comps;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // For Undirected graph
    }

    int src;
    cin >> src;

    int result = components(graph);
    cout << result;

    return 0;
}