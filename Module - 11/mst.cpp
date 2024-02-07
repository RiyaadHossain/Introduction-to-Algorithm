#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> par;
    vector<int> g_size;

public:
    vector<int> *group = &par;

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
        par[node] = parent;
        return parent;
    }

    void unionBySize(int node1, int node2)
    {
        int par1 = find(node1);
        int par2 = find(node2);

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

class Edge
{
public:
    int u, v, w;

    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    int n, e;
    cin >> n >> e;

    // 1. Store Edges
    vector<Edge> edges;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    // 2. Sort edge list
    sort(edges.begin(), edges.end(), cmp);

    // 3. Connects Nodes at Minimum cost
    DSU graph = DSU(n);

    int totalMinCost = 0;
    vector<Edge> minCostEdges;
    for (Edge ed : edges)
    {
        int par1 = graph.find(ed.u);
        int par2 = graph.find(ed.v);

        if (par1 != par2)
        {
            graph.unionBySize(ed.u, ed.v);
            totalMinCost += ed.w;
            minCostEdges.push_back(Edge(ed.u, ed.v, ed.w));
        }
    }

    cout << "Min Cost " << totalMinCost << endl;
    for (Edge ed : minCostEdges)
        cout << ed.u << " " << ed.v << " " << ed.w << endl;

    return 0;
}