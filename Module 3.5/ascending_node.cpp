#include <bits/stdc++.h>
using namespace std;

/*
    Question: You will be given an undirected graph as input. You need to tell the number of nodes in each component in ascending order.
*/

int vis[100];

int dfs(vector<vector<int>> &graph, int src)
{
    vis[src] = 1;
    int nodeCnt = 1;
    for (int ch : graph[src])
    {
        if (vis[ch] == 0)
            nodeCnt += dfs(graph, ch);
    }

    return nodeCnt;
}

vector<int> numberOfNodes(vector<vector<int>> &graph)
{
    memset(vis, 0, sizeof(vis));
    vector<int> result;
    for (int i = 0; i < graph.size(); i++)
    {
        if (vis[i] == 0)
            result.push_back(dfs(graph, i));
    }

    sort(result.begin(), result.end());

    return result;
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

    vector<int> result = numberOfNodes(graph);
    for (int num : result)
        cout << num << " ";

    return 0;
}