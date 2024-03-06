#include <bits/stdc++.h>
using namespace std;
using PairInt = pair<int, int>;
using Edge = pair<int, PairInt>;

void initCost(int cost[], int n)
{
    for (int i = 0; i < n; i++)
        cost[i] = INT_MAX;
}

bool hasNegCycle(vector<Edge> edges, int cost[])
{
    bool negativeCycle = false;
    for (int j = 0; j < edges.size(); j++)
    {
        int c = edges[j].first;
        int u = edges[j].second.first;
        int v = edges[j].second.second;
        if (cost[u] != INT_MAX && cost[u] + c < cost[v])
            negativeCycle = true;
    }

    return negativeCycle;
}

int bellmanFord(vector<Edge> edges, int n, int src, int des)
{
    int cost[n];
    initCost(cost, n);

    cost[src] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int c = edges[j].first;
            int u = edges[j].second.first;
            int v = edges[j].second.second;
            if (cost[u] != INT_MAX && cost[u] + c < cost[v]) // Update better cost
                cost[v] = cost[u] + c;
        }
    }

    bool negativeCycle = hasNegCycle(edges, cost);
    if (negativeCycle)
        return INT_MAX;

    return cost[des] != INT_MAX ? cost[des] : -1;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        Edge edge1 = {c, {u, v}}, edge2 = {c, {v, u}};
        edges.push_back(edge1);
        edges.push_back(edge2);
    }

    int src, des;
    cin >> src >> des;

    int result = bellmanFord(edges, n, src, des);
    cout << (result != INT_MAX ? to_string(result) : "Negative Weighted");

    return 0;
}