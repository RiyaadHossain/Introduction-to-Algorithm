#include <bits/stdc++.h>
using namespace std;
using PairInt = pair<int, int>;
using Edge = pair<int, PairInt>;

class DSU
{
    vector<int> par;
    vector<int> g_size;

public:
    DSU(int n)
    {
        par.resize(n, -1);
        g_size.resize(n, 1);
    }

    int find(int node)
    {
        if (par[node] == -1)
            return node;

        int parent = find(par[node]);
        par[node] = parent; // Path Compression
        return parent;
    }

    void unionBySize(int node1, int node2)
    {
        int par1 = find(node1);
        int par2 = find(node2);

        if (par1 == par2)
            return;

        if (g_size[par1] <= g_size[par2])
        {
            par[par2] = par1;
            g_size[par1] += g_size[par2];
        }
        else
        {
            par[par2] = par1;
            g_size[par1] += g_size[par2];
        }
    }
};

int mst(vector<Edge> edges, int n)
{
    sort(edges.begin(), edges.end());

    DSU dsu = DSU(n);

    int minCost = 0;
    for (int i = 0; i < n; i++)
    {
        Edge edge = edges[i];
        int a = edge.second.first, b = edge.second.second, c = edge.first;

        int par1 = dsu.find(a);
        int par2 = dsu.find(b);

        if (par1 != par2)
            minCost += c;
    }

    return minCost;
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

    int minCost = mst(edges, n);
    cout << minCost;

    return 0;
}