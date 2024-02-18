#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, ll>;

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
};

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, pi>> edges;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());

    DSU dsu = DSU(n + 1);

    ll totalMinCost = 0;
    int closeRoads = 0;
    for (pair<int, pi> ed : edges)
    {
        int w = ed.first;
        int u = ed.second.first, v = ed.second.second;

        int par1 = dsu.find(u);
        int par2 = dsu.find(v);

        if (par1 != par2)
            totalMinCost += w, n--;
        else
            closeRoads++;

        dsu.unionBySize(par1, par2);
    }

    if (n == 1)
        cout << closeRoads << " " << totalMinCost;
    else
        cout << "Not Possible";

    return 0;
}