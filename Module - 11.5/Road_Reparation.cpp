#include <bits/stdc++.h>
using namespace std;

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
        par[node] = parent;
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

    bool isPossible()
    {
        int parent = find(1);
 
        bool possible = true;
        for (int i = 2; i < par.size(); i++)
        {
            if (parent != find(i))
                possible = false;
        }

        return possible;
    }
};

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
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
        edges.push_back(Edge(u, v, c));
    }

    sort(edges.begin(), edges.end(), cmp);

    DSU group = DSU(n + 1);
    int components = n;
    long long totalCost = 0;
    for (Edge ed : edges)
    {
        int par1 = group.find(ed.u);
        int par2 = group.find(ed.v);

        if (par1 != par2)
            totalCost += ed.c, components--;

        group.unionBySize(ed.u, ed.v);
    }

    if (components == 1)
        cout << totalCost;
    else
        cout << "IMPOSSIBLE";

    return 0;
}